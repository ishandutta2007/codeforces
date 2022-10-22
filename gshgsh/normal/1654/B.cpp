#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],nxt[MAXN],pos[26];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		string s;cin>>s;N=s.length();For(i,1,N)a[i]=s[i-1]-'a';For(i,0,25)pos[i]=N+1;
		FOR(i,N,1)nxt[i]=pos[a[i]],pos[a[i]]=i;
		int x=1;while(nxt[x]!=N+1)x++;For(i,x,N)cout<<char(a[i]+'a');cout<<'\n';
	}
}