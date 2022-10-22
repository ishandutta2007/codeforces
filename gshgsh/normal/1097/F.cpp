#include<iostream>
#include<bitset>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
#define MAXM 7001
int N,M,tot,prm[MAXM],mu[MAXM];bool Not[MAXM];bitset<MAXM>a[MAXN],b[MAXM],val[MAXM];
int main()
{
	N=MAXM-1;mu[1]=1;For(i,2,N){if(!Not[i])prm[++tot]=i,mu[i]=-1;for(int j=1;j<=tot&&i*prm[j]<=N;j++){Not[i*prm[j]]=1;if(i%prm[j]==0)break;mu[i*prm[j]]=-mu[i];}}
	For(i,1,N)for(int j=i;j<=N;j+=i)b[i][j]=mu[j/i]!=0,val[j][i]=1;
	scanf("%d%d",&N,&M);For(i,1,M){int opt,x,y,z;scanf("%d%d%d",&opt,&x,&y);if(opt==2||opt==3)scanf("%d",&z);if(opt==1)a[x]=val[y];else if(opt==2)a[x]=a[y]^a[z];else if(opt==3)a[x]=a[y]&a[z];else putchar(((a[x]&b[y]).count()&1)+'0');}return 0;
}