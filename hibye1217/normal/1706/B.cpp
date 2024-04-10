#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;

vector<int> v[100020];

void Main(){
	int t; cin >> t; while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x; v[x].push_back(i);
		}
		for (int c = 1; c <= n; c++){
			int ans = 0, lst = -1;
			for (int x : v[c]){
				if (lst == -1){ lst = x; ans += 1; }
				else{
					if ((lst&1) ^ (x&1)){ lst = x; ans += 1; }
				}
			}
			cout << ans << ' ';
		}
		cout << endl;
		for (int i = 1; i <= n; i++){ v[i].clear(); }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}