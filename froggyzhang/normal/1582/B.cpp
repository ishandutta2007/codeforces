#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,A,B;
void Solve(){
	cin>>n;
	A=B=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		A+=x==0;
		B+=x==1;
	}
	cout<<(1LL<<A)*B<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}