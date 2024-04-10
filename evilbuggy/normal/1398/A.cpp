#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	if(a[0] + a[1] <= a.back()){
		cout<<1<<" "<<2<<" "<<n<<'\n';
	}else{
		cout<<-1<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin>>t;
	while(t--)solve();

	return 0;
}