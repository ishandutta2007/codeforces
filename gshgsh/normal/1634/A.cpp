#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(string s){int N=s.length();For(i,0,N-1)if(s[i]!=s[N-i-1])return 0;return 1;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get(),K=get();string s;cin>>s;
		if(!K){cout<<"1\n";continue;}
		if(check(s))cout<<"1\n";else cout<<"2\n";
	}
	return 0;
}