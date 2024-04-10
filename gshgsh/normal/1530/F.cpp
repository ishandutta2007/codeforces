#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) (x&-x)
#define P 31607
#define MAXN 21
int N,a[MAXN][MAXN],f[MAXN][1<<MAXN],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,0,N-1)For(j,0,N-1)a[i][j]=1ll*get()*pow(10000,P-2)%P;
	For(i,0,N-1){f[i][0]=1;For(j,0,N-1)f[i][1<<j]=a[i][j];For(j,1,(1<<N)-1)if(__builtin_popcount(j)>1)f[i][j]=1ll*f[i][j^lowbit(j)]*f[i][lowbit(j)]%P;}
	For(i,0,(1<<N+2)-1)
	{
		int s=i&((1<<N)-1),a=i>>N&1,b=i>>N+1&1,mul=1;
		For(j,0,N-1){int x=s;if(a)x|=1<<j;if(b)x|=1<<N-1-j;mul=1ll*mul*f[j][x]%P*(1-f[j][(1<<N)-1^x]+P)%P;}
		ans=(ans+1ll*(__builtin_popcount(i)&1?P-1:1)*mul)%P;
	}
	cout<<(1-ans+P)%P<<'\n';
}