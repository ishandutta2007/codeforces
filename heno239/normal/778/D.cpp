#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<ll, ll> LP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef long double ld;

void sousa(vector<string> &s, int x, int y) {
	if (s[x][y] == 'L') {
		s[x][y] =s[x][y+1]= 'U';
		s[x + 1][y] =s[x+1][y+1]= 'D';
	}
	else {
		s[x][y] = s[x + 1][y] = 'L';
		s[x][y + 1] = s[x + 1][y + 1] = 'R';
	}
}
vector<P> calc(vector<string> s) {
	int h = s.size();
	int w = s[0].size();
	vector<P> res;
	rep(i, h)rep(j, w) {
		if (s[i][j] == 'R' || s[i][j] == 'D')continue;
		if (i + 1 == h || j + 1 == w)continue;
		int cx = i, cy = j;
		vector<P> memo;
		memo.push_back({ cx,cy });
		int pre = -1;
		while (true) {
			int col = 0;
			if (s[cx][cy] == 'L')col = 1;
			if (pre == col)break;
			pre = col;
			if (col == 0) {
				cy++;
			}
			else {
				cx++;
			}
			//cout << cx << " " << cy << " "<<s[cx][cy]<<"\n";
			memo.push_back({ cx,cy });
		}
		memo.pop_back();
		while (memo.size()) {
			sousa(s, memo.back().first, memo.back().second);
			res.push_back(memo.back());
			memo.pop_back();
		}
		if (s[i][j] == 'L') {
			sousa(s, i, j);
			res.push_back({ i,j });
		}
	}
	return res;
}


void solve() {
	int h, w; cin >> h >> w;
	vector<string> s1(h), s2(h);
	rep(i, h)cin >> s1[i];
	rep(i, h)cin >> s2[i];

	bool rev = false;
	if (h % 2) {
		rev = true;
		swap(h, w);
		vector<string> t1(h), t2(h);
		rep(i, h){
			t1[i].resize(w);
			t2[i].resize(w);
			rep(j, w) {
				t1[i][j] = s1[j][i];
				t2[i][j] = s2[j][i];
			}
		}
		swap(s1, t1);
		swap(s2, t2);
		rep(i, h)rep(j, w) {
			char &c = s1[i][j];
			if (c == 'L')c = 'U';
			else if (c == 'R')c = 'D';
			else if (c == 'U')c = 'L';
			else c = 'R';

			char &c2 = s2[i][j];
			if (c2 == 'L')c2 = 'U';
			else if (c2 == 'R')c2 = 'D';
			else if (c2 == 'U')c2 = 'L';
			else c2 = 'R';
		}
	}

	
	vector<P> ans;
	vector<P> ans1 = calc(s1), ans2 = calc(s2);
	reverse(all(ans2));
	for (P p : ans1)ans.push_back(p);
	for (P p : ans2)ans.push_back(p);
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		int x = ans[i].first;
		int y = ans[i].second;
		if (rev)swap(x, y);
		cout <<x+1<<" "<<y+1 << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//int t; cin >> t; rep(i, t)
		solve();
	stop
		return 0;
}