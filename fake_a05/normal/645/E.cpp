#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'


#define int long long

const int maxN = 2e6 + 5, mod = 1e9 + 7;
string s;
int N, K;
int32_t last[maxN][26];
int dp[maxN];

void fill(int pos)
{
	if(!pos) 
	{
		s[pos] = 'a'; 
		return;
	}
	int mnIdx = 0;
	loop(c, 0, K - 1)
	{
		if(last[pos - 1][c] < last[pos - 1][mnIdx]) mnIdx = c;
	}
	s[pos] = char(mnIdx + 'a');
}

void getLast(int pos)
{
	if(!pos)
	{
		loop(i, 0, K - 1)
		{
			last[pos][i] = -1;
		}
		last[pos][s[0] - 'a'] = 0;
	}
	else
	{
		loop(i, 0, K - 1)
		{
			last[pos][i] = last[pos - 1][i];
		}
		last[pos][s[pos] - 'a'] = pos;
	}
}

void getDp(int pos)
{
	dp[pos] = 1;
	loop(i, 0, K - 1)
	{
		if(last[pos][i] == -1) continue;
		if(last[pos][i] == 0) dp[pos] = (dp[pos] + 1) % mod;
		else dp[pos] = (dp[pos] + dp[last[pos][i] - 1]) % mod;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	cin >> s;
	s.resize(s.length() + N, '$');
	loop(pos, 0, (int) s.length() - 1)
	{
		if(s[pos] == '$') fill(pos);
		getLast(pos);
		getDp(pos);
	}
//	cout << s << endl;
	cout << dp[(int) s.length() - 1];
}