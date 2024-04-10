#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
typedef pair<int,int> pii;
int n,a[N];
void Solve(){
	map<int,int> mp;
	vector<pii> ans;
	vector<int> pos;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];++mp[a[i]];
	}
	for(auto [x,cnt]:mp){
		if(cnt%2==1){
			cout<<-1<<'\n';
			return;
		}
	}
	int qwq=n/2;
	for(int i=1,cnt=0;i<=qwq;++i){
		int l=i,r=-1;
		for(int j=i+1;j<=n;++j){
			if(a[i]==a[j]){
				r=j;
				break;
			}
		}
		assert(~r);
		for(int j=l+1,k=0;j<r;++j,++k){
			ans.emplace_back(cnt+k+r,a[j]);
		}
		pos.push_back((r-l)*2);
		reverse(a+l+1,a+r);
		--n;
		for(int j=r;j<=n;++j)a[j]=a[j+1];
		cnt+=(r-l-1)*2+1;
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
	cout<<pos.size()<<'\n';
	for(auto x:pos){
		cout<<x<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}