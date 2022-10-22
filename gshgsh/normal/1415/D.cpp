#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 100001
int N,a[MAXN],b[MAXN],s[MAXN],ans=INF;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();For(i,1,N){a[i]=get(),s[i]=s[i-1]^a[i];FOR(j,30,0)if(a[i]&(1<<j)){b[i]=j;break;}}For(i,2,N-1)if(b[i-1]==b[i]&&b[i]==b[i+1]){cout<<1<<endl;return 0;}
	For(i,1,N)For(j,i+1,N)For(k,i,j-1)if((s[k]^s[i-1])>(s[j]^s[k]))ans=min(ans,j-i-1);cout<<(ans!=INF?ans:-1)<<endl;return 0;
}