#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
#define MAXM 1000001
int N,K,M,Q,a[MAXN],mul[MAXN],tot,prm[MAXM],Div[MAXM],Dv[MAXM],f[MAXM],g[MAXM],cnt[MAXM],ans[MAXN],now=1;bool Not[MAXM];
struct A{int l,r,id;bool operator<(A a)const{return l/K<a.l/K||(l/K==a.l/K&&(l/K&1?r<a.r:r>a.r));}}q[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int turn(int x){int y=1;while(x>1){int tmp=Div[x];y*=tmp;while(Div[x]==tmp)x=Dv[x];}return y;}
void ins(int x){int y=a[x];while(y>1)cnt[Div[y]]++,cnt[Div[y]]==1?now=1ll*now*f[Div[y]]%P:0,y=Dv[y];}
void del(int x){int y=a[x];while(y>1)cnt[Div[y]]--,!cnt[Div[y]]?now=1ll*now*g[Div[y]]%P:0,y=Dv[y];}
int main()
{
	N=get();mul[0]=1;For(i,1,N)M=max(M,a[i]=get()),mul[i]=1ll*mul[i-1]*a[i]%P;
	For(i,2,M){if(!Not[i])prm[++tot]=i,Div[i]=i,f[i]=1ll*(i-1)*pow(i,P-2)%P,g[i]=1ll*i*pow(i-1,P-2)%P;Dv[i]=i/Div[i];for(int j=1;j<=tot&&i*prm[j]<=M;j++){Not[i*prm[j]]=1;Div[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}For(i,1,N)a[i]=turn(a[i]);
	Q=get(),K=900;For(i,1,Q){int l=get(),r=get();q[i]={l,r,i},ans[i]=1ll*mul[r]*pow(mul[l-1],P-2)%P;}sort(q+1,q+Q+1);
	int l=1,r=0;For(i,1,Q){int L=q[i].l,R=q[i].r;while(r<R)ins(++r);while(l>L)ins(--l);while(r>R)del(r--);while(l<L)del(l++);ans[q[i].id]=1ll*ans[q[i].id]*now%P;}
	For(i,1,Q)put(ans[i]),putchar('\n');return 0;
}