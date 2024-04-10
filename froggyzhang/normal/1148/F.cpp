#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,m,h[N];
ll a[N],c[N],sum,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum>0){
		for(int i=1;i<=n;++i){
			a[i]=-a[i];
		}	
	}
	for(int i=1;i<=n;++i){
		h[i]=__lg(c[i]);
	}
	for(int j=0;j<=62;++j){
		ll tot=0;
		for(int i=1;i<=n;++i){
			if(h[i]==j)tot+=a[i];
		}
		if(tot<0){
			ans|=1LL<<j;
			for(int i=1;i<=n;++i){
				if(c[i]>>j&1)a[i]=-a[i];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}