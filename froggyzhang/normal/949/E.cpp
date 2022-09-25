#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
vector<int> Solve(int dep,vector<int> &a){
	if(a.size()==1&&!a[0])return vector<int>(0);
	if(dep>19)return vector<int>(233);
	bool ok=true;
	for(auto x:a){
		if(abs(x)&1){ok=false;break;}	
	}
	if(ok){
		for(auto &x:a)x>>=1;
		a.erase(unique(a.begin(),a.end()),a.end());
		return Solve(dep+1,a);
	}
	else{
		auto a1=a,a2=a;
		for(auto &x:a1){
			if(abs(x)&1)x=(x-1)/2;
			else x/=2;
		}
		for(auto &x:a2){
			if(abs(x)&1)x=(x+1)/2;
			else x/=2;
		}
		a1.erase(unique(a1.begin(),a1.end()),a1.end());
		a2.erase(unique(a2.begin(),a2.end()),a2.end());
		auto L=Solve(dep+1,a1);
		auto R=Solve(dep+1,a2);
		L.push_back(1<<dep);
		R.push_back(-(1<<dep));
		return L.size()<R.size()?L:R;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	auto ans=Solve(0,a);
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	return 0;
}