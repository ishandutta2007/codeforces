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
const int maxN = 1e5 + 5;
int tc, N, M;
int a[maxN], b[maxN], c[maxN], ans[maxN];
vector<int> C[maxN];
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
		cin >> N >> M;
		loop(col, 1, N) C[col].clear();
		loop(i, 1, M) ans[i] = -1;
		loop(i,1 , N) cin >> a[i];
		loop(i, 1, N) cin >> b[i];
		loop(i, 1, M) 
		{
			cin >> c[i];
			if(i < M) C[c[i]].eb(i);
		}
		int last = -1;
		loop(i, 1, N) if(b[i] == c[M] and a[i] != b[i]) last = i;
		if(last == -1) loop(i, 1, N) if(b[i] == c[M]) last = i;
		if(last == -1) 
		{
			cout << "NO\n";
			continue;
		}
		ans[M] = last;
		bool ok = 1;
		ans[M] = last;
		loop(i, 1, N)
		{
			if(b[i] == a[i] or i == last) continue;
			if(C[b[i]].empty()) ok = 0;
			else
			{
				ans[C[b[i]].back()] = i;
				C[b[i]].pop_back();
			}
		}
		if(ok) 
		{
			cout << "YES\n";
			loop(i, 1, M) 
			{
				if(ans[i] > 0) cout << ans[i] << sp;
				else cout << last << sp;
			}
			cout << endl;
		}
		else cout << "NO\n";
	}
}