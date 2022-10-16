#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],b[N];
bool check(int x){
	int now=0;
	for(int i=1;i<=n;++i){
		if(b[i]>=now&&a[i]>=x-now-1){
			++now;
		}
	}
	return now>=x;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1,ans=mid;
		}
		else{
			r=mid;
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