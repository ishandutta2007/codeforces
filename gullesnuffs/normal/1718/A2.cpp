#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
	
int MAX = 4;

int bruteforce(vector<int> a) {
	priority_queue<pair<int, vector<int>>> pq;
	map<vector<int>, int> dis;
	dis[a] = 0;	
	pq.push(make_pair(0, a));
	while (true) {
		auto b = pq.top().second;
		pq.pop();
		bool ok = true;
		rep(i,0,sz(b)) {
			if (b[i])
				ok = false;
		}
		if (ok)
			return dis[b];
		rep(i,0,sz(b)) {
			rep(j,i,sz(b)) {
				rep(k,0,MAX) {
					auto B = b;
					rep(l,i,j+1)
						B[l] ^= k;
					int new_dis = dis[b]+(j-i+2)/2;
					if (!dis.count(B) || new_dis < dis[B]) {
						dis[B] = new_dis;
						pq.push(make_pair(-new_dis, B));
					}
				}
			}
		}
	}
}

int solve(vector<int> a) {
	int n = sz(a);
	int ans = n;
	set<int> sums;
	sums.insert(0);
	int s = 0;
	rep(i,0,n) {
		s ^= a[i];
		if (sums.count(s)) {
			--ans;
			sums.clear();
			sums.insert(0);
			s = 0;
		} else {
			sums.insert(s);
		}
	}
	cout << ans << endl;
	return ans;
}

int main() {
	/*while (true) {
		int n = (rand()%4)+1;
		vector<int> a(n);
		rep(i,0,n)
			a[i] = rand()%MAX;
		int v1 = solve(a);	
		int v2 = bruteforce(a);	
		if (v1 != v2) {
			cerr << v1 << " " << v2 << endl;
			for (int x : a)
				cerr << x << " ";
			cerr << endl;
			assert(0);
		}
	}*/
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i,0,n)
			cin >> a[i];
		solve(a);
	}
}