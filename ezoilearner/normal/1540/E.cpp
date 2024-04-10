#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const int Mod=1000000007;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int MOD(int x){
		x%=Mod;
		if(x<0)x+=Mod;
		return x;
	}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;

int n,q;
#define Maxn 305
int a[Maxn],A[Maxn][Maxn];
int inv[Maxn];

int e[Maxn][Maxn];
int num[Maxn][Maxn],h[Maxn];

int pw[Maxn][1305];

const int inf=1e9;
int dt[Maxn];

int sum[Maxn][Maxn];

int lowbit(int x){return x&(-x);}
void ADD(int *hh,int pos,int ad){
	for(int i=pos;i<=n;i+=lowbit(i))hh[i]=add(hh[i],ad);
}
int query(int *hh,int pos){
	int res=0;
	for(int i=pos;i;i-=lowbit(i))res=add(res,hh[i]);
	return res;
}
void Build(){
	rep(i,1,n)rep(j,1,n)sum[i][j]=0;
	per(i,n,1){
		dt[i]=inf;
		if(a[i]>0)dt[i]=0;
		rep(j,i+1,n)
			if(A[i][j])dt[i]=min(dt[i],dt[j]+1);
		if(dt[i]!=inf){
			rep(j,1,i)
				if(num[i][j]){
					sum[j][dt[i]+1]=add(sum[j][dt[i]+1],mul(mul(pw[j][n-dt[i]],num[i][j]),MOD(a[i])));
				}
		}
	}
	rep(i,1,n){
		rep(j,1,n)sum[i][j]=add(sum[i][j-1],sum[i][j]);
		per(j,n,1)sum[i][j]=dec(sum[i][j],sum[i][j^lowbit(j)]);
	}
}

int main(){
	rd(n);
	inv[0]=inv[1]=1;
	rep(i,2,n)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	rep(i,1,n){
		pw[i][n]=1;
		per(j,n-1,0)pw[i][j]=mul(pw[i][j+1],inv[i]);
		rep(j,n+1,n+1000)pw[i][j]=mul(i,pw[i][j-1]);
	}
	rep(i,1,n)rd(a[i]);
	rep(i,1,n){
		int sz;
		rd(sz);
		A[i][i]=i;
		rep(j,1,sz){
			int t;rd(t);
			A[i][t]=t;
		}
	}
	rep(i,1,n){
		e[i][i]=1;
		per(j,i-1,1){
			int t=dec(i,j),tmp=0;
			rep(k,j+1,i)tmp=add(tmp,mul(e[i][k],A[j][k]));
			e[i][j]=mul(tmp,inv[t]);
		}
	}
	rep(i,1,n){
		h[i]=1;
		per(j,i,1)
			if(h[j]){
				num[i][j]=h[j];int t=h[j];
				rep(k,1,j)h[k]=dec(h[k],mul(t,e[j][k]));
			}
	}
	rep(i,1,n)
		rep(j,1,n)e[i][j]=add(e[i][j-1],e[i][j]);
	int opt,x,l,r;
	rd(q);
	Build();
	rep(tt,1,q){
		rd(opt);
		if(opt==1){
			rd(x);rd(l);rd(r);
			int res=0;
			rep(i,1,n){
				int tmp=query(sum[i],min(x+1,n));
				res=add(res,mul(mul(tmp,pw[i][x+n]),dec(e[i][r],e[i][l-1])));
			}
			rep(i,l,r)
				if(dt[i]>x)res=add(res,MOD(a[i]));
			printf("%d\n",res);
		}else{
			rd(l);rd(x);
			if(a[l]<=0&&a[l]+x>0){
				a[l]+=x;
				Build();
			}else{
				a[l]+=x;
				if(dt[l]!=inf){
				rep(i,1,l)
					if(num[l][i]){
						ADD(sum[i],dt[l]+1,mul(mul(num[l][i],x),pw[i][n-dt[l]]));
					}		
				}
			}
		}
	}
	return 0;
}