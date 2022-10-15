#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 20
int N;
int R[MAXN];
int M[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> R[i];
	}

	int c = 0;
	for (int i = 0; i < 720720; i++) {
		for (int j = 0; j < N; j++) {
			if (i % M[j] == R[j]) {
				++c;
				break;
			}
		}
	}

	cout << setprecision(20) << c / ((long double) 720720.0) << endl;
	return 0;
}