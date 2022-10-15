#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 55
#define CHECK(x) if(!(x)){cout<<"No"<<endl;return 0;}
int N;
string A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int s = -1;
	int e = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != '0') {
				s = i;
				break;
			}
		}
		if (s != -1) break;
	}

	CHECK(s != -1);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != '0') {
				e = i;
				break;
			}
		}
		if (e != -1) break;
	}

	CHECK(s != e);
	CHECK(e - s >= 2);

	int a = -1, b = -1;
	for (int i = 0; i < N; i++) {
		if (A[s][i] != '0') {
			a = i;
			break;
		}
	}
	CHECK(a != -1);
	for (int i = N - 1; i >= 0; i--) {
		if (A[s][i] != '0') {
			b = i;
			break;
		}
	}
	CHECK(b - a >= 2);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < s || i > e || j < a || j > b) {
				CHECK(A[i][j] == '0');
			}
			else {
				if ((i == s || i == e) && (j == a || j == b)) {
					CHECK(A[i][j] == '1');
				}
				else if (i != s && i != e && j != a && j != b) {
					CHECK(A[i][j] == '4');
				}
				else {
					CHECK(A[i][j] == '2');
				}
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}