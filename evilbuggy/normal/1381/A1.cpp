#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<int> ans;

inline void flip(string &a, int k){
	string ret = "";
	for(int i = 0; i < k; i++){
		if(a[i] == '1')ret += '0';
		else ret += '1';
	}
	ans.push_back(k);
	reverse(ret.begin(), ret.end());
	ret += a.substr(k);
	a = ret;
}

void solve(){
	int n;
	string a, b;
	cin>>n>>a>>b;
	ans.clear();
	for(int r = n - 1; r >= 0; r--){
		if(a[r] == b[r])continue;
		if(r == 0){
			flip(a, 1);
			break;
		}
		if(a[0] != b[r]){
			flip(a, r + 1);
		}else{
			flip(a, 1);
			flip(a, r + 1);
		}
	}
	cout<<ans.size()<<" ";
	for(auto x : ans){
		cout<<x<<" ";
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t; cin>>t;
	while(t--)solve();

	return 0;
}