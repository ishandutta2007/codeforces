#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb emplace_back
#define all(x) begin(x), end(x)

#define rand rng
#define endl '\n'
#define sp ' '

int tc;
string s;
map<char, int> cnt;
signed main()
{
//	freopen("return.in", "r", stdin);
//	freopen("return.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int px, py;
		cin >> px >> py >> s;
		bool ok = 1;
		cnt.clear();
		for(char c: s) cnt[c]++;
		if(px < 0)
		{
			ok &= (abs(px) <= cnt['L']);
		}
		if(px >= 0)
		{
			ok &= px <= cnt['R'];
		}
		if(py < 0) ok &= abs(py) <= cnt['D'];
		else ok &= py <= cnt['U'];
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}