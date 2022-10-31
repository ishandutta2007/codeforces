#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int>
#define ii pair<int, int>
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 3e5 + 5, mod = 1e9 + 7, inf = LLONG_MAX / 100ll;

int N, h[maxN], b[maxN];
int dp[maxN];


multiset<int> M;
stack<ii> st;

void del(int val){
	M.erase(M.find(val));
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	loop(i, 1, N){
		cin >> h[i];
	}
	loop(i, 1, N) cin >> b[i];
	h[0] = inf;
	loop(i, 1, N){
		int mx = dp[i - 1];
		while(!st.empty()){
			auto t = st.top();
//			cout << t.fi << sp << t.se << endl;
			if(h[t.fi] < h[i]) break;
			mx = max(mx, t.se);
//			cout << M.size() << endl;
//			cout << "delval: " << t.se << sp << b[t.fi] << endl;
			del(t.se + b[t.fi]);
			st.pop();
		}
		st.push({i, mx});
		M.insert(mx + b[i]);
//		cout << "insval" << sp <<mx << sp << b[i] << endl;
		dp[i] = * M.rbegin();
//		cout << "dp:  " << dp[i] << endl;
	}
	cout << dp[N];
}