#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],l[MAXN],r[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		string s;cin>>s;N=s.length();For(i,1,N)a[i]=s[i-1]=='?'?2:s[i-1]-'0';int r=0,now=-1,pos=0;ll ans=0;
		For(i,1,N){if(i>pos)now=-1;while(r<N&&(now==-1||a[r+1]==2||now+a[r+1]==1)){if(now==-1)now=a[r+1]==2?-1:a[r+1];else now^=1;r++;if(a[r]!=2)pos=r;}ans+=r-i+1;}cout<<ans<<endl;
	}
}