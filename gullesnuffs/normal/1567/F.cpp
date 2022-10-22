#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int get_degree(int i, int j, const vector<string>& f) {
	int deg = 0;
	rep(k,0,4) {
		if (f[i+dx[k]][j+dy[k]] != '.')
			continue;
		++deg;
	}
	return deg;
}

int get_sum(int i, int j, const vector<string>& f) {
	int sum = 0;
	rep(k,0,4) {
		char c = f[i+dx[k]][j+dy[k]];
		if (c == '1')
			sum += 1;
		else if (c == '4')
			sum -= 1;
	}
	return sum;
}

void solve(vector<string> f) {
	int n = sz(f);
	int m = sz(f[0]);
	vector<vector<int>> dis(n, vector<int>(m, n+m+5));
	vector<vector<int>> ans(n, vector<int>(m, n+m+5));
	priority_queue<tuple<int, int, int>> q;
	rep(i,0,n)
	rep(j,0,m) {
		if (!i || !j || i == n-1 || j == m-1) {
			dis[i][j] = 0;
			q.push(make_tuple(0, i, j));
		}
		if (f[i][j] == 'X' && get_degree(i, j, f)%2) {
			cout << "NO" << endl;
			return;
		}
	}
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int i = get<1>(cur);
		int j = get<2>(cur);
		rep(x,i-1,i+2)
		rep(y,j-1,j+2) {
			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			int new_dis = dis[i][j];
			if (f[x][y] == 'X')
				++new_dis;
			if ((f[x][y] == 'X' || f[i][j] == 'X') && abs(x-i) && abs(y-j))
				continue;
			if (new_dis < dis[x][y]) {
				dis[x][y] = new_dis;
				q.push(make_tuple(-new_dis, x, y));
			}
		}
	}
	cout << "YES" << endl;
	rep(i,0,n) {
	rep(j,0,m) {
		if (f[i][j] == 'X') {
			ans[i][j] = 5*(get_degree(i, j, f)/2);
			cout << 5*(get_degree(i, j, f)/2) << " ";
		}
		else if (dis[i][j]%2 == i%2) {
			ans[i][j] = 1;
			cout << 1 << " ";
		}
		else {
			ans[i][j] = 4;
			cout << 4 << " ";
		}
	}
	cout << endl;
	}
	rep(i,0,n) {
	rep(j,0,m) {
		if (f[i][j] == 'X') {
			int sum = 0;
			rep(k,0,4) {
				int x = i + dx[k];
				int y = j + dy[k];
				sum += ans[x][y];
			}
			assert(sum%5 == 0);
		}
	}
	}
}

/*void solve(vector<string> f) {
	int n = sz(f);
	int m = sz(f[0]);
	priority_queue<tuple<int, int, int, int>> pq;
	rep(i,0,n) {
	rep(j,0,m) {
		//cerr << f[i][j];
		if (f[i][j] != 'X')
			continue;
		if (get_degree(i, j, f)%2) {
			cout << "NO" << endl;
			return;
		}
		pq.push(make_tuple(-get_degree(i, j, f), 0, i, j));
	}
	//cerr << endl;
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int i = get<2>(cur);
		int j = get<3>(cur);
		if (f[i][j] != 'X')
			continue;
		int sum = get_sum(i, j, f);
		bool stop = false;
		rep(attempt,0,2) {
		rep(k,0,4) {
			if (stop)
				break;
			char& c = f[i+dx[k]][j+dy[k]];
			if (c == '.') {
				if (sum) {
					if ((i+dx[k])%2) {
						if (sum > 0)
							c = '4';
						else {
							if (attempt = 0)
								continue;
							c = '1';
						}
					}
					else {
						if (sum < 0)
							c = '1';
						else {
							if (attempt = 0)
								continue;
							c = '4';
						}
					}
				} else if ((i+dx[k])%2)
					c = '4';
				else
					c = '1';
				stop = true;
				int a = i+dx[k];
				int b = j+dy[k];
				rep(l,0,4) {
					int x = a+dx[l];
					int y = b+dy[l];
					if (x >= 0 && y >= 0 && x < n && y < m && f[x][y] == 'X') {
						pq.push(make_tuple(-get_degree(x, y, f), abs(get_sum(x, y, f)), x, y));
					}
				}
				break;
			}
		}
		}
	}
	rep(i,0,n)
	rep(j,0,m) {
		if (f[i][j] != 'X')
			continue;
		int sum = 0;
		int deg = 0;
		rep(k,0,4) {
			char c = f[i+dx[k]][j+dy[k]];
			if (c == '1') {
				sum += 1;
				++deg;
			}
			else if (c == '4') {
				sum += 4;
				++deg;
			}
		}
		if (sum%5) {
			cout << "NO" << endl;
			assert(false);
			return;
		}
		f[i][j] = '0' + sum;
	}
	cout << "YES" << endl;
	rep(i,0,n) {
		rep(j,0,m) {
			if (f[i][j] == '.')
				f[i][j] = '1';
			cout << int(f[i][j]-'0') << " ";
		}
		cout << endl;
	}
}*/

vector<string> generate_random(int n, int m) {
	vector<string> f(n);
	rep(i,0,n)
	rep(j,0,m) {
		if (i == 0 || j == 0 || i == n-1 || j == m-1 || rand()%2)
			f[i].push_back('.');
		else
			f[i].push_back('X');
	}
	return f;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> f(n);
	rep(i,0,n)
		cin >> f[i];
	solve(f);
}

int main() {
	/*while (true) {
		int n = (rand()%10)+1;
		int m = (rand()%10)+1;
		auto input = generate_random(n, m);
		solve(input);
	}*/
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
		solve();
}