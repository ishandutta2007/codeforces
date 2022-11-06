#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int M=700;
const int mo=998244353;
int totp,tot,pri[M],id[N][M],f[N*M],v[N*M];
ll a[N*M],s[N*M],d[N*M];
int main(){
	rep(i,2,5000){bool fl=1;
		rep(j,1,totp)if(!(i%pri[j])){
			fl=0;break;
		}
		if(fl)pri[++totp]=i;
	}tot=1;
	rep(i,1,totp+1)id[1][i]=1;
	rep(i,2,5000){
		int fl=0;id[i][totp+1]=1;
		dep(j,totp,1)if(pri[j]<=i){
			if(!fl&&!(i%pri[j]))fl=2;
			if(fl){
				id[i][j]=++tot;
				if(fl==2){
					f[tot]=id[i-1][j];fl=1;
					for(int x=i;!(x%pri[j]);x/=pri[j])++d[tot];
				}else{
					f[tot]=id[i][j+1];
					for(int x=i/pri[j];x;x/=pri[j])d[tot]+=x;
				}
			}else id[i][j]=id[i-1][j];
		}else id[i][j]=1;
	}int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x<2)++s[1];else ++s[id[x][1]];
	}
	dep(i,tot,2)s[f[i]]+=s[i],a[f[i]]+=a[i]+s[i]*d[i];
	ll ans=a[1];
	rep(i,2,tot)a[i]=a[f[i]]+(n-s[i]*2)*d[i],ans=min(ans,a[i]);
	printf("%lld\n",ans);
}