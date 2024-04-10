#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
map<int,int> mp;
void Solve(){
	cin>>n>>m;
	mp.clear();
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++mp[x];
	}
	int rem=m;
	int pos=0;
	for(int i=0;;++i){
		if(!mp.count(i)){
			if(!rem){
				pos=i;
				break;
			}
			--rem;
		}
	}
	vector<int> A;
	int ans=0;
	for(auto [x,w]:mp){
		if(x>pos){
			A.push_back(w);
			++ans;
		}
	}
	sort(A.begin(),A.end());
	for(auto x:A){
		if(x>m)break;
		m-=x;
		--ans;
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