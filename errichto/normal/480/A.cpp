#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define RI(i,n) for(int i = 1, _n = (n); i <= _n; ++i)
const int inf = 1e9 + 5, nax = 1e6 + 5;



int main()
{
	ios_base :: sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<pii > w;
	RE(_, n) {
		int a, b;
		cin >> a >> b;
		w.pb(mp(a, b));
	}
	sort(w.begin(), w.end());
	int L = 0;
	RE(i, n) {
		if(w[i].second >= L) L = w[i].second;
		else L = w[i].first;
	}
	cout << L;
	
	return 0;
}