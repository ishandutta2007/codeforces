#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int H=4;
bool isprime(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;	
}
inline int Get(int x){
	while(!isprime(x))++x;
	return x;	
}
const int mod[H]={1145141,100000007,1000000009,Get(rnd()%(1000000007))};
char s[N],t[N];
int n,m;
struct Hash{
	int a[H];
	Hash(){memset(a,0,sizeof(a));}
	Hash operator = (int x){
		for(int i=0;i<H;++i)a[i]=x;
		return *this;	
	}
	Hash operator * (int x){
		Hash h;
		for(int i=0;i<H;++i)h.a[i]=1LL*a[i]*x%mod[i];
		return h;	
	}
	Hash operator + (int x){
		Hash h;
		for(int i=0;i<H;++i)h.a[i]=(a[i]+x)%mod[i];
		return h;	
	}
	friend Hash operator + (const Hash &h1,const Hash &h2){
		Hash h3;
		for(int i=0;i<H;++i){
			h3.a[i]=(h1.a[i]+h2.a[i])%mod[i];
		}
		return h3;
	}
	friend Hash operator - (const Hash &h1,const Hash &h2){
		Hash h3;
		for(int i=0;i<H;++i){
			h3.a[i]=(h1.a[i]-h2.a[i]+mod[i])%mod[i];
		}
		return h3;
	}
	friend Hash operator * (const Hash &h1,const Hash &h2){
		Hash h3;
		for(int i=0;i<H;++i){
			h3.a[i]=1LL*h1.a[i]*h2.a[i]%mod[i];
		}
		return h3;
	}
	friend bool operator == (const Hash &h1,const Hash &h2){
		for(int i=0;i<H;++i){
			if(h1.a[i]^h2.a[i])return false;
		}
		return true;
	}
}hs[N],ht[N],pw[N],MOD;
inline Hash Get(int l,int r,Hash *h){
	return h[r]+((MOD-h[l-1])*pw[r-l+1]);	
}
void init(char *s,Hash *h,int n){
	h[0]=0;
	for(int i=1;i<=n;++i){
		h[i]=h[i-1]*10+(s[i]-'0');
	}
}
inline void check(int i,int j,int k){
	if(Get(j+1,k,hs)+Get(i+1,j,hs)==ht[m]){
		cout<<i+1<<' '<<j<<'\n'<<j+1<<' '<<k<<'\n';
		exit(0);	
	}	
}
int Lcp(int pl,int pr){
	int l=1,r=pr-pl+2,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(Get(pl,pl+mid-1,hs)==Get(1,mid,ht)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}	
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<H;++i)MOD.a[i]=mod[i];
	cin>>(s+1)>>(t+1);
	n=strlen(s+1),m=strlen(t+1);
	pw[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=pw[i-1]*10;
	}
	init(s,hs,n);
	init(t,ht,m);
	for(int i=1;i<=n;++i){
		for(int j=max(0,i-m-1);j<=min(i-1,i-m+1);++j){
			for(int k=max(i+1,i+m-1);k<=min(n,i+m+1);++k){
				check(j,i,k);	
			}
		}
	}
	for(int i=1;i<=n-m;++i){
		int lcp=Lcp(i+1,min(n,i+m));
		if(!lcp)continue;
		int z=m-lcp;
		for(int j=max(0,i-z-1);j<=min(i-1,i-z+1);++j){
			check(j,i,i+m);
		}
		for(int j=max(0,i+m+z-1);j<=min(n,i+m+z+1);++j){
			check(i,i+m,j);
		}
	}
	return 0;
}