#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 600001
int N,M,f[MAXN],tot,res[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get(),M=get();For(i,1,M+1)f[i]=i;For(i,1,N){int K=get(),x1=get(),x2=K>1?get():M+1;if(getf(x1)!=getf(x2))f[getf(x1)]=getf(x2),res[++tot]=i;}
	int ans=1;For(i,1,tot)ans=ans*2%P;cout<<ans<<' '<<tot<<endl;For(i,1,tot)cout<<res[i]<<' ';return 0;
}