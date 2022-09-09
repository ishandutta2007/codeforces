#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

map<pii,char> t;

inline pii rev(const pii &p){ return make_pair(p.second, p.first);}
inline bool has_t(const pii &p){ return t.find(p) != t.end();}

inline char read_c(void)
{
	static char s[10];
	scanf("%s",s+1);
	return s[1];
}

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	int codd = 0, ceven = 0;
	while(Q--)
	{
		char op = read_c();
		if(op == '+')
		{
			int u,v;
			scanf("%d%d",&u,&v);
			char c = read_c();
			pii p = make_pair(u,v), rp = rev(p);
			t[p] = c;
			if(has_t(rp))
			{
				++codd;
				if(t[rp] == c) ++ceven;
			}
		}
		else if(op == '-')
		{
			int u,v;
			scanf("%d%d",&u,&v);
			pii p = make_pair(u,v), rp = rev(p);
			if(has_t(rp))
			{
				--codd;
				if(t[rp] == t[p]) --ceven;
			}
			t.erase(p);
		}
		else
		{
			int k;
			scanf("%d",&k);
			if(k&1) printf(codd? "YES\n": "NO\n");
			else printf(ceven? "YES\n": "NO\n");
		}
	}
	return 0;
}