#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef tuple<ll, ll, ll> pt;

const int N = 8;
ll A[10][5];

inline ll sq(ll a) {return a * a;}
inline ll sq(ll a, ll b) {return sq(a - b);}

inline ll dist(int a, int b = 0) { return sq(A[a][0], A[b][0]) + sq(A[a][1], A[b][1]) + sq(A[a][2], A[b][2]); }

pt operator +(pt a, pt b) {
	return pt(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b), get<2>(a) + get<2>(b));
}

bool dfs(int pos = 1) {
	if(pos == N) {
		ll s = dist(1);
		for(int i = 2; i < 8; i++) s = min(s, dist(i));
		if(!s) return 0;
		vector<pt> d1, d2, d3;
		for(int i = 1; i < 8; i++) {
			pt cur(A[i][0] - A[0][0], A[i][1] - A[0][1], A[i][2] - A[0][2]);
			if(dist(i) == s) {
				d1.push_back(cur);
			} else if(dist(i) == s * 2) {
				d2.push_back(cur);
			} else if(dist(i) == s * 3) {
				d3.push_back(cur);

			} else return false;
		}
		if(d1.size() != 3 || d2.size() != 3 || d3.size() != 1) return false;
		sort(d2.begin(), d2.end());
		vector<pt> v;
		v.push_back(d1[0] + d1[1]);
		v.push_back(d1[0] + d1[2]);
		v.push_back(d1[1] + d1[2]);
		sort(v.begin(), v.end());
		if(d2 != v) return false;

		if(d3[0] != d1[0] + d1[1] + d1[2]) return false;
		
		return true;
	} else {
		if(dfs(pos + 1)) return true;
		swap(A[pos][1], A[pos][2]);
		if(dfs(pos + 1)) return true;
		swap(A[pos][0], A[pos][1]);
		if(dfs(pos + 1)) return true;
		swap(A[pos][1], A[pos][2]);
		if(dfs(pos + 1)) return true;
		swap(A[pos][0], A[pos][1]);
		if(dfs(pos + 1)) return true;
		swap(A[pos][1], A[pos][2]);
		if(dfs(pos + 1)) return true;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	for(int i = 0; i < 8; i++) for(int j = 0; j < 3; j++) cin >> A[i][j];
	if(dfs()) {
		cout  << "YES\n";
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 3; j++) {
				cout << A[i][j] << ' ';
			}
			cout << '\n';
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}