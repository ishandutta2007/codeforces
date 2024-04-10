#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 2333
int n,a[N],l,r,k;
void Solve(){
	cin>>n>>l>>r>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]>=l&&a[i]<=r&&a[i]<=k){
			k-=a[i];++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}