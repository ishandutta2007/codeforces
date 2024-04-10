#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[300020];

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			pq.push({arr[i], i});
		}
		bool ans = false;
		while (!pq.empty()){
			int val = pq.top().fr, idx = pq.top().sc;
			if (idx == 1){
				cout << "YES" << endl;
				ans = true;
				break;
			}
			if (idx == n){
				cout << "NO" << endl;
				break;
			}
			pq.pop();
		}
	}
}