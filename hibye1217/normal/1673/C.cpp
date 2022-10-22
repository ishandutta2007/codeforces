#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int mod = 1e9 + 7;
int dp[40001][498], prf[40001][498];

inline string rev(const string& s){ int sl = s.size();
	string res = "";
	for (int i = sl-1; i >= 0; i--){ res += s[i]; }
	return res;
}

inline string its(int x){
	string res = "";
	while (x){ res += (char)(x%10 + 48); x /= 10; }
	return rev(res);
}
inline int sti(const string& s){ int sl = s.size();
	int res = 0;
	for (char ch : s){ res *= 10; res += ch-48; }
	return res;
}

vector<int> pal;
void Main(){
	for (int i = 1; i <= 400; i++){
		string s = its(i); int sl = s.size();
		//cout << s + rev(s) << ' ' << s.substr(sl-1) + rev(s) << endl;
		int v1 = sti( s + rev(s) ), v2 = sti( s.substr(0, sl-1) + rev(s) );
		if (v1 <= 40000){ pal.push_back(v1); }
		if (v2 <= 40000){ pal.push_back(v2); }
	}
	unq(pal); int M = pal.size();
	//cout << M << endl;
	dp[0][0] = 1; for (int i = 0; i < M; i++){ prf[0][i] = 1; }
	for (int i = 1; i <= 40000; i++){
		for (int j = 0; j < M; j++){
			int x = pal[j];
			if (i < x){ continue; }
			dp[i][j] = prf[i-x][j];
		}
		prf[i][0] = dp[i][0];
		for (int j = 1; j < M; j++){
			prf[i][j] = prf[i][j-1] + dp[i][j]; prf[i][j] %= mod;
		}
	}
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << prf[n][M-1] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}