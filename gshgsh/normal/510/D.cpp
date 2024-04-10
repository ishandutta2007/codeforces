#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 301
#define MAXM 200001
int N,a[MAXN],b[MAXN],M,val[MAXM],f[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();int x=a[1];For(i,2,N)x=__gcd(x,a[i]);if(x!=1){cout<<"-1\n";return 0;}
	For(i,1,N)for(int j=1;j*j<=a[i];j++)if(a[i]%j==0){val[++M]=j;if(j*j!=a[i])val[++M]=a[i]/j;}
	sort(val+1,val+M+1);M=unique(val+1,val+M+1)-val-1;memset(f,0x3f,sizeof(f));
	For(i,1,N){For(j,1,M){int x=lower_bound(val+1,val+M+1,__gcd(a[i],val[j]))-val;f[x]=min(f[x],f[j]+b[i]);}int x=lower_bound(val+1,val+M+1,a[i])-val;f[x]=min(f[x],b[i]);}
	cout<<f[1]<<'\n';return 0;
}