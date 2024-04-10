#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

inline bool isL(char c){ return c >= 'A' && c <= 'Z';}

struct Box
{
	vector<string> a;
	Box(void){}
	Box(string s)
	{
		a.resize(3);
		a[0] = a[2] = "+-" + string(s.size(), '-') + "-+";
		a[1] = "+ " + s + " +";
	}
	Box(char c){ *this = Box(string(1,c));}
	inline int get_r(void) const { return a.size();}
	inline int get_c(void) const { return a.size()? a[0].size(): 0;}
	inline string& operator [] (const int x){ return a[x];}
	inline const string& operator [] (const int x) const { return a[x];}
	
	inline void resize_all(int len,char c1 = ' ')
	{
		for(int i=0; i<(int)a.size(); ++i)
			a[i].resize(len, i == 1? c1: ' ');
	}
	
	inline void add_up(void){ a.insert(a.begin(), string(a[0].size(), ' '));}
	inline void add_down(void){ a.push_back(string(a[0].size(), ' '));}
	inline void resize_r(int len){ a.resize(len, string(a[0].size(), ' '));}
	
	inline void add_rarrow(void)
	{
		for(int i=0; i<(int)a.size(); ++i)
			a[i] += i == 1? "->+": "   ";
	}
	inline void add_larrow(void)
	{
		for(int i=0; i<(int)a.size(); ++i)
			a[i] = (i == 1? "+->": "   ") + a[i];
	}
	inline void add_lrarrow(void){ add_larrow(); add_rarrow();}
	
	inline void add_bound(void)
	{
		int l = (int)a.size(), r = 0;
		for(int i=0; i<(int)a.size(); ++i)
			if(a[i][0] == '+') l = min(l,i), r = i;
		for(int i=l; i<=r; ++i)
			if(a[i][0] != '+')
				a[i][0] = *(a[i].end() - 1) = '|';
	}
	
	inline void push_right(const Box &oth)
	{
		for(int i=0; i<(int)a.size(); ++i)
			a[i] += oth[i];
	}
	inline void push_down(const Box &oth){ a.insert(a.end(), oth.a.begin(), oth.a.end());}
	inline void push_down(const string &s){ a.push_back(s);}
	inline void push_up(const string &s){ a.insert(a.begin(), s);}
};

inline string get_rarrow(int len){ return "+" + string(len-3, '-') + ">+";}
inline string get_larrow(int len){ return "+<" + string(len-3, '-') + "+";}

inline void make_connect(Box &a,Box &b)
{
	int mx = max(a.get_r(), b.get_r());
	a.resize_r(mx); b.resize_r(mx);
	a.resize_all(a.get_c() + 2);
	*(a[1].end() - 2) = '-'; *(a[1].end() - 1) = '>';
	a.push_right(b);
}

inline void make_or(vector<Box> &vec)
{
	int mx = 0;
	for(int i=0; i<(int)vec.size(); ++i)
		mx = max(mx, vec[i].get_c());
	for(int i=0; i<(int)vec.size(); ++i)
		vec[i].resize_all(mx, '-'),
		vec[i].add_lrarrow();
	
	for(int i=1; i<(int)vec.size(); ++i)
		vec[0].add_down(), vec[0].push_down(vec[i]);
	vec[0].add_bound();
}

inline void make_plus(Box &a)
{
	a.add_lrarrow();
	a.add_down(); a.push_down(get_larrow(a.get_c()));
	a.add_bound();
}

inline void make_quest(Box &a)
{
	a.add_lrarrow();
	a.add_up(); a.push_up(get_rarrow(a.get_c())); a.add_up();
	a.add_bound();
}

inline void make_star(Box &a)
{
	a.add_lrarrow();
	a.add_up(); a.push_up(get_rarrow(a.get_c())); a.add_up();
	a.add_down(); a.push_down(get_larrow(a.get_c()));
	a.add_bound();
}

char s[MAXN];
int to[MAXN], lstb[MAXN];

inline Box expr(int l,int r);
inline Box term(int l,int r);
inline Box atom(int &r);

inline void print(int l,int r)
{
	printf("[%d, %d]: ",l,r);
	for(int i=l; i<=r; ++i) putchar(s[i]);
	putchar('\n');
}

inline Box expr(int l,int r)
{
	if(lstb[r] < l) return term(l,r);
	vector<Box> vec;
	int pos = r;
	while(lstb[pos] >= l)
	{
		vec.push_back(term(lstb[pos]+1, pos));
		pos = lstb[pos] - 1;
	}
	vec.push_back(term(l, pos));
	reverse(vec.begin(), vec.end());
	make_or(vec);
	return vec[0];
}

inline Box term(int l,int r)
{
	int pos = r;
	vector<Box> vec;
	while(pos >= l)
	{
		if(!isL(s[pos]))
		{
			vec.push_back(atom(pos));
			continue;
		}
		int lst = pos;
		while(pos >= l && isL(s[pos])) --pos;
		vec.push_back(Box(string(s+pos+1, s+lst+1)));
	}
	reverse(vec.begin(), vec.end());
	for(int i=1; i<(int)vec.size(); ++i)
		make_connect(vec[0], vec[i]);
	return vec[0];
}

inline Box atom(int &r)
{
	if(s[r] == ')')
	{
		Box res = expr(to[r] + 1, r - 1);
		r = to[r] - 1;
		return res;
	}
	if(s[r] == '+')
	{
		Box res = atom(--r); make_plus(res);
		return res;
	}
	if(s[r] == '?')
	{
		Box res = atom(--r); make_quest(res);
		return res;
	}
	if(s[r] == '*')
	{
		Box res = atom(--r); make_star(res);
		return res;
	}
	return Box(s[r--]);
}

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	stack<int> sta;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(') sta.push(i);
		if(s[i] == ')') to[i] = sta.top(), sta.pop();
		
		lstb[i] = s[i] == '|'? i: s[i] == ')'? lstb[to[i]]: lstb[i-1];
	}
	
	Box res = expr(1,n);
	res.add_lrarrow();
	res.a[1][0] = 'S';
	*(res.a[1].end() - 1) = 'F';
	
	printf("%d %d\n",res.get_r(),res.get_c());
	for(int i=0; i<(int)res.get_r(); ++i)
		cout << res[i] << endl;	
	return 0;
}