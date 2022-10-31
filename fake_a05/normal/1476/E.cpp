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

#define int long long
const int maxN = 1e5 + 5;
int N, M, K;
map<int, int> id;
bool inst[maxN];
vi sooner[maxN];
vi topo;
vi match[maxN];
int p[maxN];
bool ok[maxN];
int Hash(string s)
{
	int re = 0;
	for(char c: s)
	{
		if(c == '_') re = re * 31;
		else re = re * 31 + c - 'a' + 1;
	}
	return re;
}
void dfs(int i)
{
	inst[i] = 1;
	for(int j: sooner[i]) if(!inst[j]) dfs(j);
	topo.eb(i);
}
signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	loop(i, 1, N)
	{
		string s;
		cin >> s;
		int t = Hash(s);
		id[t] = i;
	}
	loop(i, 1, M)
	{
		string s;
		cin >> s;
		vi all;
		loop(mask, 0, (1 << K) - 1)
		{
			string ss;
			loop(bit, 0, K - 1) 
			{
				if(mask >> bit & 1) ss.push_back(s[bit]);
				else ss.push_back('_');
			}
			int t = Hash(ss);
//			cout << s << sp << ss << sp << t << endl;
			if(!id.count(t)) continue;
			match[id[t]].eb(i);
			all.eb(id[t]);
		}
		cin >> p[i];
		bool temp_ok = 0;
		for(int &o: all)
		{
//			cout << i << " have " << o << endl;
			if(o == p[i]) 
			{
				temp_ok = 1;
				continue;
			}
			sooner[o].eb(p[i]);
		}
		if(!temp_ok) return cout << "NO", 0;
	}
	loop(i, 1, N)
	{
//		for(int o: sooner[i]) cout << o << " sooner " <<i << endl;
		if(!inst[i]) dfs(i);
	}
	for(int j: topo)
	{
		for(int i: match[j]) 
		{
			if(ok[i]) continue;
			else if(p[i] == j) ok[i] = 1;
			else return cout << "NO", 0;
		}
	}
	cout << "YES" << endl;
	for(int j: topo) cout << j << sp;
}