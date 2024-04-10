#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

inline void rd(ll &x){
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

const int Mod=998244353;
const int I2=499122177;
namespace modular{
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;} 
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			b>>=1;
			a=1ll*a*a%Mod; 
		}
		return res;
	}
}using namespace modular;

int n,m;
#define Maxn 200010
ll a[Maxn];

ll sta[64];int cnt;ll seq[64]; 
void Add(ll x){
	per(i,m-1,0)
		if(x&(1ll<<i)){
			if(!sta[i]){
				seq[cnt]=x;
				sta[i]=x;cnt++;
				break;
			}
			x^=sta[i];
		}
}

int Ans[64];
int bin[1<<18];
const int All=(1<<18)-1;

int bitsc(ll x){
	return bin[x&All]+bin[(x>>18)&All]+bin[(x>>36)&All];
}

int lowbit(int x){return x&(-x);} 

void dfs(int u,ll p){
	if(u==cnt){
		Ans[bitsc(p)]++;
		return;	
	}
	dfs(u+1,p);
	dfs(u+1,p^seq[u]);
}

ll num[64];
ll b[64];ll val[64];

ll hh[64];int len=0;

int way[64];
void gao(int u,ll p,int c){
	if(u==len){
		int t=bitsc(p)+c;
		way[t]=add(way[t],1);
		return;
	}
	gao(u+1,p,c);
	gao(u+1,p^hh[u],c+1);
}

int CC[64][64];
int C(int a,int b){
	if(a<b)return 0;
	return CC[a][b];
}
void calc(){
	if(cnt<=m/2){
		dfs(0,0ll); 
		return;
	}
	CC[0][0]=1;
	rep(i,0,m){
		CC[i][0]=1;
		rep(j,1,i)CC[i][j]=add(CC[i-1][j],CC[i-1][j-1]);
	}
	rep(i,0,m-1)sta[i]=0;
	rep(i,0,cnt-1)
		rep(j,0,m-1)
			if(seq[i]&(1ll<<j))sta[j]^=(1ll<<i);
	rep(t,0,m-1){
		ll x=sta[t],tmp=(1ll<<t);
		per(i,cnt-1,0)
			if(x&(1ll<<i)){
				if(!b[i]){
					b[i]=x;val[i]=tmp;
					break;
				} 
				x^=b[i];tmp^=val[i];
			}
		if(!x)hh[len++]=tmp^(1ll<<t);
	}
	gao(0,0ll,0);
	int cur=Fast_Pow(2,cnt);cur=mul(cur,Fast_Pow(I2,m));
	rep(I,0,m){
		rep(T,0,m){
			int res=0;
			rep(i,0,min(T,I)){
				int zz=i;
				int pp=mul(C(T,i),C(m-T,I-i));
				if(zz&1)res=dec(res,pp);
				else res=add(res,pp);
			}
			Ans[I]=add(Ans[I],mul(way[T],res));
		}
		Ans[I]=mul(Ans[I],cur);
	}
}

int main(){
	rd(n);rd(m);
	bin[0]=0;rep(i,1,All)bin[i]=bin[i^lowbit(i)]+1;
	rep(i,1,n){
		rd(a[i]);
		Add(a[i]);
	}
	calc();
	int cur=Fast_Pow(2,n-cnt);
	rep(i,0,m)Ans[i]=mul(Ans[i],cur);
	rep(i,0,m)printf("%d ",Ans[i]);
	puts("");
	return 0;
}