#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

inline bool ok(int x, int y, int n){
	return 0 <= x && 0 <= y && x < n && y < n;
}

int main(){

	int n = nxt(), k = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	const int xx[4] = {-1, 0, 1, 0};
	const int yy[4] = {0, 1, 0, -1};

	vector<vector<int>> num(n, vector<int>(n, -1));
	int cnt = 0;
	vector<int> size;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == '.' && num[i][j] == -1){
				vector<pair<int, int>> st(1, {i, j});
				num[i][j] = cnt;
				size.push_back(0);
				while (!st.empty()){
					pair<int, int> p = st.back();
					st.pop_back();
					size.back()++;
					for (int _ = 0; _ < 4; _++){
						if (!ok(p.first + xx[_], p.second + yy[_], n))
							continue;
						if (a[p.first + xx[_]][p.second + yy[_]] == 'X')
							continue;
						if (num[p.first + xx[_]][p.second + yy[_]] == -1){
							num[p.first + xx[_]][p.second + yy[_]] = cnt;
							st.emplace_back(p.first + xx[_], p.second + yy[_]);
						}
					}
				}
				cnt++;
			}
		}
	}

	vector<vector<vector<int>>> adj(n, vector<vector<int>>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int _ = 0; _ < 4; _++){
				if (!ok(i + xx[_], j + yy[_], n))
					continue;
				if (num[i + xx[_]][j + yy[_]] > -1)
					adj[i][j].push_back(num[i + xx[_]][j + yy[_]]);
			}
			if (num[i][j] > -1)
				adj[i][j].push_back(num[i][j]);
		}
	}

	vector<int> occ(cnt);
	int fr = 0;
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			for (auto x : adj[i][j])
				occ[x]++;
			if (a[i][j] == 'X')
				fr++;
		}
	}
	int ans = fr;
	for (int i = 0; i < cnt; i++)
		if (occ[i])
			ans += size[i];

	int cur = ans;

	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++){
	// 		cerr << num[i][j] + 1;
	// 	}
	// 	cerr << "\n";
	// }

	// cerr << cur << "\n";
	int I = 0, J = 0;
	while (true){
		if (I % 2 && J == 0){
			if (I == n - k)
				break;
			for (int i = 0; i < k; i++){
				for (int x : adj[I][J + i]){
					occ[x]--;
					if (occ[x] == 0)
						cur -= size[x];
				}
				if (a[I][J + i] == 'X')
					cur--;
			}
			for (int i = 0; i < k; i++){
				for (int x : adj[I + k][J + i]){
					if (occ[x] == 0)
						cur += size[x];
					occ[x]++;
				}
				if (a[I + k][J + i] == 'X')
					cur++;
			}
			I++;
			ans = max(ans, cur);
		} else if (I % 2 == 0 && J == n - k){
			if (I == n - k)
				break;
			for (int i = 0; i < k; i++){
				for (int x : adj[I][J + i]){
					occ[x]--;
					if (occ[x] == 0)
						cur -= size[x];
				}
				if (a[I][J + i] == 'X')
					cur--;
			}
			for (int i = 0; i < k; i++){
				for (int x : adj[I + k][J + i]){
					if (occ[x] == 0)
						cur += size[x];
					occ[x]++;
				}
				if (a[I + k][J + i] == 'X')
					cur++;
			}
			I++;
			ans = max(ans, cur);
		} else if (I % 2 == 0){
			for (int i = 0; i < k; i++){
				for (int x : adj[I + i][J]){
					occ[x]--;
					if (occ[x] == 0)
						cur -= size[x];
				}
				if (a[I + i][J] == 'X')
					cur--;
			}
			for (int i = 0; i < k; i++){
				for (int x : adj[I + i][J + k]){
					if (occ[x] == 0)
						cur += size[x];
					occ[x]++;
				}
				if (a[I + i][J + k] == 'X')
					cur++;
			}
			J++;
			ans = max(ans, cur);
		} else {
			J--;
			for (int i = 0; i < k; i++){
				for (int x : adj[I + i][J + k]){
					occ[x]--;
					if (occ[x] == 0)
						cur -= size[x];
				}
				if (a[I + i][J + k] == 'X')
					cur--;
			}
			for (int i = 0; i < k; i++){
				for (int x : adj[I + i][J]){
					if (occ[x] == 0)
						cur += size[x];
					occ[x]++;
				}
				if (a[I + i][J] == 'X')
					cur++;
			}
			ans = max(ans, cur);
		}
		// cerr << cur << " ";
	}

	cout << ans << "\n";

	return 0;
}