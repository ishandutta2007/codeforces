#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
ll m;
inline ll sqr(int x){
	return 1LL*x*x;
}
inline ll calc(int x,int k){
	return sqr(x/k+1)*(x%k)+sqr(x/k)*(k-x%k);
}
pair<int,ll> check(ll c){
	int cnt=0;
	ll sum=0;
	for(int i=0;i<n;++i){
		int w=a[i+1]-a[i];
		int l=1,r=w,p=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(calc(w,mid)-calc(w,mid+1)>=c){
				p=mid,l=mid+1;
			}
			else{
				r=mid;
			}
		}
		cnt+=p;
		sum+=calc(w,p+1);
	}
	return make_pair(cnt,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	ll l=1,r=1e18,ans=-1;
	while(l<r){
		ll mid=(l+r)>>1;
		auto [cnt,sum]=check(mid);
		if(sum<=m){
			ans=cnt-(m-sum)/mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans<<'\n';
	return 0;
}