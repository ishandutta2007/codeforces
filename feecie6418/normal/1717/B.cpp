#include<bits/stdc++.h>
using namespace std;
void Solve(){
	int n,k,r,c;
	cin>>n>>k>>r>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)%k==(r+c)%k)cout<<'X';
			else cout<<'.';
		}
		puts("");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}