#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,x,a[N];
multiset<ll> S;
void Solve(){
	cin>>n>>x;
	S.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		S.insert(a[i]);
	}
	int jb=0;
	for(auto it=S.begin();it!=S.end();++it){
		ll w=1LL*x*(*it);
		if(S.count(w)){
			S.erase(S.find(w));
			++jb;
		}
	}
	cout<<S.size()-jb<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}