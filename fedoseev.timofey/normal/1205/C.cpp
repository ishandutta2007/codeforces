#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <vector <int>> A;

/*bool ask(int x1, int y1, int x2, int y2) {	
	if (A[x1][y1] != A[x2][y2]) return false;
	bool good = false;
	if (x2 - x1 == 2) {
		good |= (A[x1][y1 + 1] == A[x1 + 1][y1 + 1]);
		good |= (A[x1 + 1][y1] == A[x1 + 2][y1]);
		good |= (A[x1 + 1][y1] == A[x1 + 1][y1 + 1]);
	} else {
		good |= (A[x1][y1 + 1] == A[x1][y1 + 2]);
		good |= (A[x1 + 1][y1] == A[x1 + 1][y1 + 1]);
		good |= (A[x1][y1 + 1] == A[x1 + 1][y1 + 1]);
	}
	return good;
}*/

bool ask(int x1, int y1, int x2, int y2) {	
	if (make_pair(x1, y1) > make_pair(x2, y2)) {
		swap(x1, x2);
		swap(y1, y2);
	}
	cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
	int fl;
	cin >> fl;
	return fl;
}

bool my_ask(vector <vector <int>> &a, int x1, int y1, int x2, int y2) {	
	if (a[x1][y1] != a[x2][y2]) return false;
	if (abs(x2 - x1) + abs(y2 - y1) == 3) {
		bool good = false;
		if (x2 - x1 == 2) {
			good |= (a[x1][y1 + 1] == a[x1 + 1][y1 + 1]);
			good |= (a[x1 + 1][y1] == a[x1 + 2][y1]);
			good |= (a[x1 + 1][y1] == a[x1 + 1][y1 + 1]);
		} else {
			good |= (a[x1][y1 + 1] == a[x1][y1 + 2]);
			good |= (a[x1 + 1][y1] == a[x1 + 1][y1 + 1]);
			good |= (a[x1][y1 + 1] == a[x1 + 1][y1 + 1]);
		}
		return good;
	} else {
		return true;
	}
}

vector <vector <int>> get(vector <vector <int>> a, int dx, int dy) {
	bool fl1 = ask(0 + dx, 0 + dy, 1 + dx, 2 + dy);
	bool fl2 = ask(0 + dx, 0 + dy, 2 + dx, 1 + dy);
	bool fl3 = ask(0 + dx, 1 + dy, 2 + dx, 2 + dy);
	bool fl4 = ask(1 + dx, 0 + dy, 2 + dx, 2 + dy);
	bool fl5 = ask(0 + dx, 1 + dy, 1 + dx, 2 + dy);
	bool fl6 = ask(1 + dx, 0 + dy, 2 + dx, 1 + dy);
	vector <vector <int>> ans;
	for (int mask = 0; mask < (1 << 4); ++mask) {
		vector <vector <int>> b = a;
		int uk = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (b[i][j] == -1) {
					b[i][j] = (mask >> uk) & 1;
					++uk;
				}
			}
		}
		bool good = (my_ask(b, 0, 0, 1, 2) == fl1) & (my_ask(b, 0, 0, 2, 1) == fl2) & (my_ask(b, 0, 1, 2, 2) == fl3) & (my_ask(b, 1, 0, 2, 2) == fl4) && (fl5 == (b[0][1] == b[1][2])) && (fl6 == (b[1][0] == b[2][1]));
		if (good) {
			if (ans.empty()) {
				ans = b;
			} else {
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						cout << ans[i][j] << ' ';
					}
					cout << endl;
				}
				cout << endl;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						cout << b[i][j] << ' ';
					}
					cout << endl;
				}
				assert(false);
			}
		}
	}
	return ans;
}

int n;

bool ok(int x, int y, int nx, int ny) {
	return (nx >= x && ny >= y) || (nx <= x && ny <= y);
}

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n, -1));
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    auto make = [&] (int x, int y) {
    	queue <pair <int, int>> q;
    	q.push({x, y});
    	while (!q.empty()) {
    		auto p = q.front();
    		q.pop();
    		int x = p.first, y = p.second;
    		for (int dx = -2; dx <= 2; ++dx) {
    			for (int dy = -2; dy <= 2; ++dy) {
    				if (abs(dx) + abs(dy) != 2) continue;
    				if (ok(x + dx, y + dy) && ok(x, y, x + dx, y + dy) && a[x + dx][y + dy] == -1) {
    					a[x + dx][y + dy] = a[x][y] ^ 1 ^ ask(x, y, x + dx, y + dy);
    					q.push({x + dx, y + dy});
    				}
    			}
    		}
    	}
    };	
    make(0, 0);
    for (int i = 0; i < n; ++i) {
    	if (a[i][i] == 1 && a[i + 2][i + 2] == 0) {
    		vector <vector <int>> b(3, vector <int> (3));
    		for (int j = 0; j < 3; ++j) {
    			for (int k = 0; k < 3; ++k) {
    				b[j][k] = a[i + j][i + k];
    			}
    		}
    		b = get(b, i, i);
    		for (int j = 0; j < 3; ++j) {
    			for (int k = 0; k < 3; ++k) {
    				a[i + j][i + k] = b[j][k];
    			}
    		}
    		make(i + 1, i);
    		break;
    	}
    }
    cout << "!\n";
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cout << a[i][j];
    	}
    	cout << '\n';
    }
}