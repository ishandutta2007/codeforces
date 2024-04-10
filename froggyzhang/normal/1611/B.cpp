#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int a,b;
	cin>>a>>b;
	cout<<min(min(a,b),(a+b)/4)<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}