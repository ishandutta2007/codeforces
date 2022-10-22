#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,a[MAXN],b[MAXN],c[MAXN],lg2[MAXN];ll d[MAXN],mx[MAXN][20],mn[MAXN][20];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll askmx(int l,int r){int k=lg2[r-l+1];return max(mx[l][k],mx[r-(1<<k)+1][k]);}ll askmn(int l,int r){int k=lg2[r-l+1];return min(mn[l][k],mn[r-(1<<k)+1][k]);}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get(),c[i]=b[i]-a[i],d[i]=mx[i][0]=mn[i][0]=d[i-1]+c[i];For(i,2,N)lg2[i]=lg2[i>>1]+1;
	for(int j=1;(1<<j)<=N;j++)For(i,1,N-(1<<j)+1)mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]),mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
	For(i,1,M){int l=get(),r=get();if(d[r]!=d[l-1]||askmn(l,r)<d[l-1])cout<<-1<<'\n';else cout<<askmx(l,r)-d[l-1]<<'\n';}return 0;
}