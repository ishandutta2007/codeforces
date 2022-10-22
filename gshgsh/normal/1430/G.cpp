#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 18
int N,M,E[MAXN][MAXN],val[1<<MAXN],in[1<<MAXN],f[1<<MAXN],pre[1<<MAXN],dep[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void getdep(int s,int v){if(s==0)return;int t=s^pre[s];For(i,0,N-1)if(t>>i&1)dep[i]=v;getdep(pre[s],v+1);}
int main()
{
	N=get(),M=get();For(i,1,M){int x=get()-1,y=get()-1;in[1<<y]|=1<<x;E[x][y]=get();}For(i,0,N-1)For(j,0,(1<<N)-1)if(j>>i&1)in[j]|=in[j^1<<i];
	For(i,0,(1<<N)-1)For(j,0,N-1)if(i>>j&1)For(k,0,N-1)if(!(i>>k&1))val[i]+=E[j][k];For(i,1,(1<<N)-1)f[i]=1e9;
	For(i,0,(1<<N)-2){int s=(1<<N)-1^i,v=val[i];for(int j=s;j;j=j-1&s)if((in[j]|i)==i&&f[i^j]>f[i]+v)f[i^j]=f[i]+v,pre[i^j]=i;}
	getdep((1<<N)-1,1);For(i,0,N-1)cout<<dep[i]<<" \n"[i==N-1];
}