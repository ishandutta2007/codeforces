#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	cin>>n;
	int jb=0;
	for(int i=1,x;i<=n;++i){
		cin>>x;jb+=x&1;
	}
	cout<<min(jb,n-jb)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}