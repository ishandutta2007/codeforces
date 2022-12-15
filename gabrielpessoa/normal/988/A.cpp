#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2005, mv = 2e5+5;
const ll mod = 1e9+7;

int a[ms];
vector<int> v;

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		bool rep = false;
		for(int j = 0; j < i; j++) {
			if(a[i] == a[j]) {
				rep = true;
				break;
			}
		}
		if(!rep) {
			v.push_back(i+1);
		}
	}
	if(v.size() >= k) {
		cout << "YES\n";
		for(int i = 0; i < k; i++) {
			cout << v[i] << ' ';
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}