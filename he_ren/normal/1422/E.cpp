#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

inline void get_ans(string &ans,const string &s)
{
	if((int)s.size() <= 10) ans = s, reverse(ans.begin(), ans.end());
	else
	{
		ans.resize(10);
		for(int i=0; i<5; ++i) ans[i] = *(s.end() - i - 1);
		
		ans[5] = ans[6] = ans[7] = '.';
		ans[8] = s[1];
		ans[9] = s[0];
	}
}

inline void add_front(string &ans,char c)
{
	if((int)ans.size() < 10){ ans = c + ans; return;}
	if(ans[5] == '.')
	{
		for(int i=4; i>0; --i)
			ans[i] = ans[i-1];
		ans[0] = c;
		return;
	}
	for(int i=4; i>0; --i)
		ans[i] = ans[i-1];
	ans[0] = c;
	ans[5] = ans[6] = ans[7] = '.';
}

char s[MAXN];
string ans[MAXN];
int ans_size[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	string curs;
	int size = 0;
	for(int i=n,j=n; i>=1; i=j)
	{
		while(j>=1 && s[j] == s[i]) --j;
		
		string cur_ans;
		get_ans(cur_ans, curs);
		
		for(int k=j+1; k<=i; ++k)
			ans[k] = cur_ans,
			ans_size[k] = size;
		
		int fir_dif = 1;
		while(fir_dif <= (int)curs.size() && *(curs.end() - fir_dif) == s[i])
			++fir_dif;
		
		for(int k=i; k>j; --k)
		{
			add_front(cur_ans, s[k]);
			if(fir_dif > (int)curs.size() || *(curs.end() - fir_dif) < s[k])
			{
				if((i-k+1)&1)
					add_front(ans[k], s[k]),
					++ans_size[k];
			}
			else
				ans[k] = cur_ans,
				ans_size[k] += i-k+1;
		}
		
		if(fir_dif > (int)curs.size() || *(curs.end() - fir_dif) < s[i])
		{
			if((i-j)&1) curs += s[i], ++size;
		}
		else curs += string(i-j,s[i]), size += i-j;
	}
	
	for(int i=1; i<=n; ++i)
		cout<<ans_size[i]<<' '<<ans[i]<<endl;
	return 0;
}