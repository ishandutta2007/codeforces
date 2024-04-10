#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100
int N,M,x,K,cnt[10];
struct Matrix
{
	int a[MAXN][MAXN];Matrix(){memset(a,0,sizeof(a));}Matrix(int x){For(i,0,K-1)For(j,0,K-1)a[i][j]=x*(i==j);}int*operator[](int x){return a[x];}
	Matrix operator*(Matrix b){Matrix ans;For(i,0,K-1)For(j,0,K-1)For(k,0,K-1)ans[i][j]=(ans[i][j]+1ll*a[i][k]*b[k][j])%P;return ans;}
}base;
Matrix pow(Matrix a,int b){Matrix ans(1);while(b)(b&1)&&(ans=ans*a,0),a=a*a,b>>=1;return ans;}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main(){M=get(),N=get(),x=get(),K=get();For(i,1,M)cnt[get()]++;For(i,0,K-1)For(j,1,9)base[(i*10+j)%K][i]+=cnt[j];cout<<pow(base,N)[x][0]<<'\n';return 0;}