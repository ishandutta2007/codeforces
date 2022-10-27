#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int a[N];

void solve(){
	int n;
	cin >> n;
	set<int> st;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st.insert(a[i]);
	}
	int lo = 0, hi = n + 1;
	for(int i = 1; i <= n; i++){
		if(a[lo + 1] == i){
			lo++;
		}else if(a[hi - 1] == i){
			hi--;
		}else{
			break;
		}
	}
	int mn = n + 1;
	for(int i = lo + 1; i < hi; i++){
		mn = min(mn, a[i]);
	}
	if(st.size() == n && (*st.rbegin()) == n){
		cout << 1;
	}else{
		cout << 0;
	}
	if(n == 1){
		cout << '\n';
		return;
	}
	for(int k = 2; k < n; k++){
		if(lo + k + 1 < hi){
			cout << 0;
		}else if(lo + k + 1 == hi){
			if(mn == n - k + 1){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			if(mn >= n - k + 1){
				cout << 1;
			}else{
				cout << 0;
			}
		}
	}
	if(st.count(1))cout << 1;
	else cout << 0;
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}