#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	cin>>n;
	int ans=0;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		ans^=(x-1)&1;
	}
	cout<<(ans?"errorgorn\n":"maomao90\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}