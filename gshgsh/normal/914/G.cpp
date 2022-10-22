#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define popcnt(x) __builtin_popcount(x)
#define I2 500000004
#define P 1000000007
#define N 17
int M,f[1<<N],a[1<<N],b[N+1][1<<N],c[N+1][1<<N],x[1<<N],y[1<<N],z[1<<N],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void OR(int*a,int f){For(i,0,N-1)For(j,0,(1<<N)-1)if(j>>i&1)a[j]=(a[j]+1ll*f*a[j^1<<i])%P;else j+=(1<<i)-1;}
void AND(int*a,int f){For(i,0,N-1)For(j,0,(1<<N)-1)if(!(j>>i&1))a[j]=(a[j]+1ll*f*a[j^1<<i])%P;else j+=(1<<i)-1;}
void XOR(int*a,int f){for(int o=2,k=1;o<=1<<N;o<<=1,k<<=1)for(int i=0;i<1<<N;i+=o)For(j,0,k-1){int p=i+j,q=i+j+k,x=a[p],y=a[q];a[p]=1ll*f*(x+y)%P,a[q]=1ll*f*(x-y+P)%P;}}
int main()
{
	M=get();For(i,1,M)a[get()]++;f[0]=0;f[1]=1;For(i,2,(1<<N)-1)f[i]=(f[i-1]+f[i-2])%P;
	For(i,0,(1<<N)-1)b[popcnt(i)][i]=a[i];For(i,0,N)OR(b[i],1);
	For(i,0,N)For(j,0,i)For(k,0,(1<<N)-1)c[i][k]=(c[i][k]+1ll*b[j][k]*b[i-j][k])%P;
	For(i,0,N)OR(c[i],P-1);For(i,0,(1<<N)-1)x[i]=c[popcnt(i)][i];
	For(i,0,(1<<N)-1)y[i]=a[i],z[i]=a[i];XOR(z,1);For(i,0,(1<<N)-1)z[i]=1ll*z[i]*z[i]%P;XOR(z,I2);
	For(i,0,(1<<N)-1)x[i]=1ll*x[i]*f[i]%P,y[i]=1ll*y[i]*f[i]%P,z[i]=1ll*z[i]*f[i]%P;
	AND(x,1);AND(y,1);AND(z,1);For(i,0,(1<<N)-1)x[i]=1ll*x[i]*y[i]%P*z[i]%P;
	AND(x,P-1);For(i,0,N-1)ans=(ans+x[1<<i])%P;cout<<ans<<'\n';return 0;
}