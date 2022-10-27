#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	
	int f = 0;
	int z = 0;
	set<int> s;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 0){
			z++;
		}else if(s.count(x)){
			f++;
		}else{
			s.insert(x);
		}
	}
	if(z){
		cout << n - z << '\n';
	}else if(f){
		cout << n << '\n';
	}else{
		cout << n + 1 << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}