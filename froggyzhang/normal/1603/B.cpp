#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int x,y;
void Solve(){
	cin>>x>>y;
	if(x>y){
		cout<<x+y<<'\n';
	}
	else if(x==y){
		cout<<x<<'\n';
	}
	else{
		ll jp=(y/x)*x;
		cout<<(y+jp)/2<<'\n';	
	}
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