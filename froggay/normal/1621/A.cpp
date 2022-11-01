#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
void Solve(){
	cin>>n>>m;
	if(m>(n+1)/2){
		cout<<-1<<'\n';
		return;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j&&i&1&&(i+1)/2<=m){
				cout<<'R';
			}
			else cout<<'.';
		}	
		cout<<'\n';
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