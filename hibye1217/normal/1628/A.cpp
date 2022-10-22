#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

vector<int> v[200020];
int ptr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		set<int> used;
		for (int i = 0; i < n; i++){
			int x; cin >> x; v[x].push_back(i);
			used.insert(x);
		}
		vector<int> ans;
		int p = 0;
		while (p < n){
			int pos=p;
			//cout << "P " << p << endl;
			for (int i = 0; i <= n; i++){
				while (ptr[i] < v[i].size()){
					if (v[i][ ptr[i] ] < p){ ptr[i] += 1; }
					else{ break; }
				}
				//cout << "PI " << i << ' ' << ptr[i] << endl;
				if (ptr[i] == v[i].size()){
					ans.push_back(i); p = pos+1;
					break;
				}
				else{
					//cout << "POS " << v[i][ ptr[i] ] << endl;
					pos = max(pos, v[i][ ptr[i] ]);
				}
			}
		}
		cout << ans.size() << endl;
		for (int x : ans){ cout << x << ' '; }
		cout << endl;
		for (int x : used){ v[x].clear(); ptr[x] = 0; }
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}