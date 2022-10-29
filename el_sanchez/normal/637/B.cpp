#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second




int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> q(n);
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;		
		
		q[i] = a;
	}
	set<string> u;
	vector<string> qq;
	for (int i = n-1; i >= 0; i--)
	   if (u.find(q[i]) == u.end()) {qq.pb(q[i]); u.insert(q[i]);}
	for (int i = 0; i < (int)qq.size(); i++) cout << qq[i] << "\n";
	return 0;
}