#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
set<int> S;
int n,a[N],m;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	S.clear();
	for(int i=1;i<=n;++i){
		if(S.count(m+a[i])||S.count(a[i]-m)){
			cout<<"YES\n";
			return;
		}
		S.insert(a[i]);
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}