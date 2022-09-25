#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	cin>>n;
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		cout<<"? "<<1<<' '<<mid<<endl;
		int cnt=0;
		for(int i=1;i<=mid;++i){
			int x;
			cin>>x;
			cnt+=x<=mid;
		}
		if(cnt&1)ans=mid,r=mid;
		else l=mid+1;
	}
	cout<<"! "<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}