#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int B=500;
const int MD=B*N;
int n,a[N],ans;
int cnt[N+B*N+N];
void Solve(){
	for(int k=0;k<=B;++k){
		for(int i=1;i<=n;++i){
			int u=a[i]-k*i+MD;
			++cnt[u];
			ans=max(ans,cnt[u]);
		}
		for(int i=1;i<=n;++i){
			int u=a[i]-k*i+MD;
			cnt[u]=0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n&&j<=i+B+1;++j){
			if(a[j]>a[i]&&(a[j]-a[i])%(j-i)==0){
				ans=max(ans,(++cnt[(a[j]-a[i])/(j-i)])+1);
			}
		}
		for(int j=i+1;j<=n&&j<=i+B+1;++j){
			if(a[j]>a[i]&&(a[j]-a[i])%(j-i)==0){
				cnt[(a[j]-a[i])/(j-i)]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	Solve();
	for(int i=1;i<=n;++i){
		a[i]=100001-a[i];
	}
	Solve();
	cout<<n-ans<<'\n';
	return 0;
}