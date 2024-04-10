#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin>>t;
	while(t--){
		int cnt = 0;
		int mn = 2e9;
		for(int i = 0; i < 4; i++){
			int x; cin>>x;
			if(x&1)cnt++;
			if(i < 3)mn = min(mn, x);
		}
		if(cnt == 0){
			cout<<"Yes\n";
		}else if(cnt == 1){
			cout<<"Yes\n";
		}else if(cnt == 2){
			cout<<"No\n";
		}else if(cnt == 3){
			if(mn > 0)cout<<"Yes\n";
			else cout<<"No\n";
		}else{
			cout<<"Yes\n";
		}
	}

	return 0;
}