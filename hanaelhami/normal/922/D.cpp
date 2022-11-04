#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ld long double
const int maxn = 1e5 + 10 , mod = 1e9 + 7;

int n;
string s[maxn];

inline ll t (string x)
{
	ll now = 0, ans = 0;
	for (int i = x.size()-1; i >= 0; i--)
		if (x[i] == 'h')
			now ++;
		else
			ans += now;
	return ans;
}

inline bool cmp (string i, string j)
{
	return (t (i + j) > t (j + i));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort (s, s + n, cmp);
	string ans;
	for (int i = 0; i < n; i++)
		ans += s[i];
	cout << t(ans) << endl;
	return 0;
}