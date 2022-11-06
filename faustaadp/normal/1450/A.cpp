#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << "\n";
	}
}