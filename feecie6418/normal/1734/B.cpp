#include<bits/stdc++.h>
using namespace std;
int n;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<(j==1||j==i)<<' ';
		}
		puts("");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}