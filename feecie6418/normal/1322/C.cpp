#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct P{
	double sums,sumc;
	ll v,is;
	bool operator <(const P p) const {
		return fabs(sums-p.sums)<1e-6?sumc<p.sumc:sums<p.sums;
	}
}a[500005];
vector<ll> vec;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),vec.clear();
		for(int i=1;i<=n;i++)scanf("%lld",&a[i].v),a[i].sums=a[i].sumc=a[i].is=0;
		for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),a[y].sums+=sin(x),a[y].sumc+=cos(x),a[y].is=1;
		//for(int i=1;i<=n;i++)cout<<a[i].v<<' '<<a[i].sums<<' '<<a[i].sumc<<endl;
		sort(a+1,a+n+1);
		ll now=0;
		for(int i=1;i<=n;i++){
			if(!a[i].is)continue;
			if(fabs(a[i].sums-a[i-1].sums)+fabs(a[i].sumc-a[i-1].sumc)<=2e-6)now+=a[i].v;
			else {
				if(now)vec.push_back(now);
				now=a[i].v;
			}
			//cout<<i<<' '<<now<<endl; 
		}
		if(now)vec.push_back(now);
		now=vec[0];
		for(ll i:vec)now=__gcd(now,i);
		cout<<now<<'\n';
	}
    return 0;
}