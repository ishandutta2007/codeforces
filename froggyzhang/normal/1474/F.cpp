#include<bits/stdc++.h>
using namespace std;
#define N 53
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,ans,d[N];
ll mx,s[N];
int len;
struct Matrix{
	int g[N][N];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=1;i<=len;++i){
			for(int j=1;j<=len;++j){
				for(int k=1;k<=len;++k){
					c.g[i][j]=(c.g[i][j]+1LL*a.g[i][k]*b.g[k][j])%mod;
				}
			}
		}
		return c;
	}
}e;
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;	
}
int tot;
struct Seg{
	ll l,r;
	Seg(ll _l=0,ll _r=0){l=_l,r=_r;}
	inline bool In(ll x){
		return x>=min(l,r)&&x<=max(l,r);
	}
}h[N<<1];
int Solve(int l,int r){
	static ll b[N*10],bn;
	bn=0; 
	tot=0;
	h[tot=1]=Seg(0,0);
	ll u=0;
	for(int i=l;i<=r;++i){
		if(!d[i])continue;
		if(d[i]<0)h[++tot]=Seg(u-1,u+d[i]);
		else h[++tot]=Seg(u+1,u+d[i]);
		u+=d[i];
	}	
	for(int i=1;i<=tot;++i){
		for(int j=-1;j<=1;++j){
			b[++bn]=h[i].l+j;
			if(b[bn]<0||b[bn]>mx)--bn;
			b[++bn]=h[i].r+j;
			if(b[bn]<0||b[bn]>mx)--bn;
		}
	}
	sort(b+1,b+bn+1);
	bn=unique(b+1,b+bn+1)-b-1;
	len=tot;
	Matrix now;
	for(int i=1;i<=tot;++i){
		if(min(h[i].l,h[i].r)==0)now.g[1][i]=1;	
	} 
	for(int i=1;i<=len;++i){
		e.g[i][i]=1;	
	}
	for(int i=2;i<=bn;++i){
		Matrix s;
		for(int j=1;j<=tot;++j){
			for(int k=j;k<=tot;++k){
				if(h[j].In(b[i-1])&&h[k].In(b[i])){
					if(j!=k||h[j].l<=h[j].r)s.g[j][k]=1;	
				}
			}	
		}
		now=now*mpow(s,b[i]-b[i-1]);		
	} 
	int all=0;
	for(int i=1;i<=tot;++i){
		all=(all+now.g[1][i])%mod;
	}
	return all;
}
int main(){
	n=read();
	read();
	ll mn=0,now=0;
	for(int i=1;i<=n;++i){
		d[i]=read();
		now+=d[i];
		mx=max(mx,now-mn);
		mn=min(mn,now);
		s[i]=now;
	}
	if(mx==0){
		ans=((1-now)%mod+mod)%mod;
	}
	else{
		for(int i=1;i<=n;++i){
			for(int j=n;j>=i;--j){
				if(s[j]-s[i-1]==mx){
					ans=(ans+Solve(i,j))%mod;
					i=j;
					break;
				}
			}
		}
	}
	printf("%lld %d\n",mx+1,ans);
	return 0;
}