#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
void Get(vector<int> &V){
	int k;
	cin>>k;
	while(k--){
		int x;
		cin>>x;
		V.push_back(x);
	}
	sort(V.begin(),V.end());
}
void Solve(){
	ll mx=0;
	cin>>n>>m;
	vector<int> U,D,L,R;
	Get(U),Get(D),Get(L),Get(R);
	mx=max(mx,1LL*(U.back()-U[0])*m);
	mx=max(mx,1LL*(D.back()-D[0])*m);
	mx=max(mx,1LL*(L.back()-L[0])*n);
	mx=max(mx,1LL*(R.back()-R[0])*n);
	cout<<mx<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}