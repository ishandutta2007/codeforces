#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<0<<'\n';
	}
	else if(n==1||m==1){
		cout<<1<<'\n';
	}
	else{
		cout<<2<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}