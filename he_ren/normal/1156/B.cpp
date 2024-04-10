#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

char s[MAXN];
int t[30 + 5];

inline bool can(string &s)
{
	for(int i=1; i<(int)s.size(); ++i)
		if(s[i]-s[i-1]==-1 || s[i]-s[i-1]==1)
			return 0;
	return 1;
}

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=0; i<26; ++i) t[i] = 0;
	for(int i=1; i<=n; ++i)
		++t[s[i]-'a'];
	
	string a;
	for(int i=0; i<26; i+=2)
		a += string(t[i], i+'a');
	
	string b;
	for(int i=1; i<26; i+=2)
		b += string(t[i], i+'a');
	
	string ss = a+b;
	if(can(ss)) cout<<ss<<endl;
	else
	{
		ss = b+a;
		if(can(ss)) cout<<ss<<endl;
		else cout<<"No answer"<<endl;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}