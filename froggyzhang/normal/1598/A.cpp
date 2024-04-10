#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string a,b;
void Solve(){
	cin>>n>>a>>b;
	for(int i=0;i<n;++i){
		if(a[i]=='1'&&b[i]=='1'){
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}