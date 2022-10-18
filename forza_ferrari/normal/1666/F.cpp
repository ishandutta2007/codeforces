#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5010,mod=998244353;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
	inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
	inline modint &operator^=(int k){
	    modint ret=1,tmp=*this;
	    for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
	    return val=ret.val,*this;
	}
	inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
	inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
	inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
	inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
	inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
	template<class T>friend modint operator+(modint a,T b){return a+=b;}
	template<class T>friend modint operator-(modint a,T b){return a-=b;}
	template<class T>friend modint operator*(modint a,T b){return a*=b;}
	template<class T>friend modint operator^(modint a,T b){return a/=b;}
	template<class T>friend modint operator/(modint a,T b){return a/=b;}
	friend modint operator^(modint a,int b){return a^=b;}
	friend bool operator==(modint a,int b){return a.val==b;}
	friend bool operator!=(modint a,int b){return a.val!=b;}
	inline bool operator!(){return !val;}
	inline modint operator-(){return val?mod-val:0;}
	inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi f[2][maxn][maxn],ifac[maxn],inv[maxn];
int cnt[maxn],n,t_case;
int main(){
	ifac[0]=ifac[1]=inv[1]=1;
	for(ri i=2;i<=5000;++i){
		inv[i]=(mod-mod/i)*inv[mod%i];
		ifac[i]=ifac[i-1]*inv[i];
	}
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		clear(cnt,n);
		ri mx=0;
		for(ri i=1,x;i<=n;++i)scanf("%d",&x),++cnt[x],ckmax(mx,x);
		if(cnt[mx]>1){puts("0");continue;}
		for(ri i=0;i<=n;++i)clear(f[0][i],n),clear(f[1][i],n);
		f[0][1][0]=1;
		mi mul=ifac[cnt[mx]];
		for(ri i=1,pre=0;i<mx;++i){
			mul*=ifac[cnt[i]];
			for(ri j=0;j<=pre;++j){
				f[0][i+1][j+cnt[i]]+=f[0][i][j];
				f[1][i+1][j+cnt[i]]+=f[1][i][j];
				if(cnt[i]){
					f[1][i+1][j+cnt[i]-1]+=f[0][i][j]*cnt[i];
					if(j)f[1][i+1][j+cnt[i]-2]+=f[1][i][j]*j*cnt[i];
				}
			}
			pre+=cnt[i];
		}
		printf("%d\n",f[1][mx][0]*mul);
	}
	return 0;
}