#include<bits/stdc++.h>
using namespace std;
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
int type;
namespace Sol_1{
	ll R;
	void Solve(){
		R=read();
		for(ll x=1;;++x){
			ll tmp=R-x*x-x-1;
			if(tmp<=0)break;
			if(tmp%(2*x)==0){
				printf("%lld %lld\n",x,tmp/(2*x));
				return;
			}
		}
		printf("NO\n");
	}
}
namespace Sol_2{
	#define N 200002
	int n,ok[N],a[N];
	char s[N];
	bool check(int x){
		for(int i=1;i<=x;++i){
			int p=0;
			for(int j=i;j<=n;j+=x){
				p^=a[j];
			}	
			if(p)return false;
		}	
		return true;
	}
	void Solve(){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i){
			a[i]=s[i]-'0';
		}
		for(int i=1;i<=n;++i){
			if(n%i==0){
				ok[i]=check(i);
			}
		}
		int ans=0;
		for(int i=0;i<n;++i){
			ans+=ok[__gcd(n,i)];
		}
		printf("%d\n",ans);
	}	
	#undef N
}
namespace Sol_3{
	#define N 1000010
	int qpow(int a,int b,int mod){
		int ans=1;
		while(b){
			if(b&1)ans=1LL*ans*a%mod;
			a=1LL*a*a%mod;
			b>>=1;
		}
		return ans;
	}
	int n,m,a[N],ntp[N];
	char s[N];	
	pair<int,int> ans;
	void init(int n){
		ntp[1]=1;
		for(int i=2;i<=n;++i){
			if(!ntp[i]){
				for(int j=i+i;j<=n;j+=i){
					ntp[j]=1;
				}
			}
		}
	}
	mt19937 rnd(time(0));
	bool check(int d){
		static int c[N];
		for(int i=0;i<d;++i)c[i]=0;
		for(int i=0;i<n;++i){
			c[i%d]+=a[i];
		}
		for(int z=m/d*d+d;z<1000000;z+=d){
			int p=z+1;
			if(ntp[p])continue;
			int r0=rnd()%(p-2)+1;
			if((r0=qpow(r0,z/d,p))!=1){
				int r=r0;
				for(int i=1;i<d;++i,r=1LL*r*r0%p){
					int tot=0;
					for(int j=d-1;j>=0;--j){
						tot=(1LL*tot*r+c[j])%p;
					}
					if(tot==0){
						ans=make_pair(p,r);
						return true;
					}
				}	
			}
		}
		return false;
	}
	void Solve(){
		n=read(),m=read();
		init(1000000);
		scanf("%s",s);
		for(int i=0;i<n;++i){
			a[i]+=s[i]-'a'+1;
		}
		scanf("%s",s);
		for(int i=0;i<n;++i){
			a[i]-=s[i]-'a'+1;
		}
		for(int d=3;d<=1000000;++d){
			if(!ntp[d]){
				if(check(d))break;
			}	
		}
		printf("%d %d\n",ans.first,ans.second);
	}
}
int main(){
	type=3;
	if(type==1){
		Sol_1::Solve();
	}
	else if(type==2){
		Sol_2::Solve();
	}
	else{
		Sol_3::Solve();
	}
	return 0;
}