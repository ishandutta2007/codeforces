#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2e5+5, mv = 2e5+5;
const ll mod = 1e9+7;

map<int, pair<int, int>> dic;
int seq[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int k;
	cin >> k;
	for(int i = 1; i <= k; i++) {
		int n;
		cin >> n;
		int sum = 0;
		for(int j = 1; j <= n; j++) {
			cin >> seq[j];
			sum += seq[j];
		}
		for(int j = 1; j <= n; j++) {
			int key = sum - seq[j];
			if(dic.count(key) && dic[key].first != i) {
				cout << "YES" << endl;
				cout << dic[key].first << ' ' << dic[key].second << endl;
				cout << i << ' ' << j << endl;
				return 0;
			} else {
				dic[key] = ii(i, j);
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}