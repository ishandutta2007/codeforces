#include<bits/stdc++.h>
using namespace std;
#define N 1010
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
namespace MR{
	const ll a[7]={2,3,5,7,11,13,17};
	ll qpow(ll a,ll b,ll p){
		ll ans=1;
		while(b){
			if(b&1)ans=(__int128)ans*a%p;
			a=(__int128)a*a%p;
			b>>=1;
		}
		return ans;
	}
	inline bool test(ll x,ll p){
		return qpow(x,p-1,p)==1;
	}
	bool Miller_Rabin(ll x,ll p){
		if(!test(x,p))return false;
		ll k=p-1;
		while(!(k&1)){
			k>>=1;
			ll t=qpow(x,k,p);
			if(t!=1&&t!=p-1)return false;
			if(t==p-1)return true;
		}
		return true;
	}
	bool check(ll p){
		for(int i=0;i<7;++i){
			if(a[i]==p)return true;
			if(!Miller_Rabin(a[i],p))return false;
		}
		return true;
	}	
}
int n,k,ok[N];
ll a[N];
__int128 qpow(__int128 a,ll b){
	__int128 ans=1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
map<ll,vector<ll> > mp;
int main(){
	n=read(),k=read();
	if(k==1)return !printf("0\n");
	for(int i=1;i<=n;++i){
		a[i]=read();
		bool ip=false;
		for(int k=2;k<=64;++k){
			ll t=pow(a[i],1.0/k)-1;
			while(qpow(t,k)<a[i])++t;
			if(qpow(t,k)==a[i]&&MR::check(t)){
				mp[t].push_back(a[i]);
				ip=true;
				break;
			}
		}
		if(!ip&&MR::check(a[i]))mp[a[i]].push_back(a[i]),ip=true;
		ok[i]=ip;
	}
	int c=0;
	for(auto [p,v]:mp){
		if((int)v.size()>=2)++c;
	}
	if(2*c>=k){	
		if(k&1){
			ll o=0;
			for(auto [p,v]:mp){	
				if((int)v.size()>=3){
					o=p;
					printf("%lld %lld %lld ",v[0],v[1],v[2]);
					k-=3;
					break;
				}
			}
			if(o){
				for(auto [p,v]:mp){
					if(o==p)continue;
					if(!k)break;
					if((int)v.size()>=2){
						printf("%lld %lld ",v[0],v[1]);
						k-=2;
					}
				}
			}
			else{
				for(int i=1;i<=n;++i){
					if(!ok[i]){
						ll x=a[i];
						int gg=0;
						for(auto [p,v]:mp){
							if((int)v.size()>=2&&x%p==0){
								while(x%p==0)x/=p;
								++gg;	
							}	
						}
						if(gg<=(k>>1)&&x==1){
							printf("%lld ",a[i]);
							--k;
							for(auto [p,v]:mp){	
								if((int)v.size()>=2&&a[i]%p==0){
									printf("%lld %lld ",v[0],v[1]);
									k-=2;
								}
							}
							for(auto [p,v]:mp){
								if(!k)break;
								if((int)v.size()>=2&&a[i]%p!=0){
									printf("%lld %lld ",v[0],v[1]);
									k-=2;
								}
							}
							return 0;
						}
					}		
				}	
				printf("0\n");
			}
		}
		else{
			for(auto [p,v]:mp){
				if(!k)break;
				if((int)v.size()>=2){
					printf("%lld %lld ",v[0],v[1]);
					k-=2;
				}
			}	
		}
	}
	else{
		vector<ll> vec;
		for(int i=1;i<=n;++i){
			if(!ok[i]){
				ll x=a[i];
				int gg=0;
				for(auto [p,v]:mp){
					if((int)v.size()>=2&&x%p==0){
						while(x%p==0)x/=p;
						++gg;	
					}	
				}
				if(x==1){
					vec.push_back(a[i]);
				}
			}		
		}
		ll tot=vec.size();
		for(auto [p,v]:mp){
			if((int)v.size()>=2)tot+=v.size();
		}
		if(tot<k){
			return !printf("0\n");
		}
		for(auto [p,v]:mp){
			if((int)v.size()>=2){
				printf("%lld %lld ",v[0],v[1]);
				k-=2;
			}
		}
		for(auto [p,v]:mp){
			if((int)v.size()>=2){
				for(int i=2;k&&i<(int)v.size();++i,--k){
					printf("%lld ",v[i]);
				}
			}
		}
		for(auto x:vec){
			if(!k)break;
			printf("%lld ",x);
			--k;
		}
	}
	return 0;
}

/*lie kai*/