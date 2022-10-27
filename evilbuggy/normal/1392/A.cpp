#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	int n; cin>>n;
	set<int> st;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		st.insert(x);
	}
	if(st.size() == 1)cout<<n<<'\n';
	else cout<<1<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}