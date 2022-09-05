#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e5+5;

ll ile[nax];
ll t[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	RE(i, n) {
		int a;
		cin >> a;
		ile[a]++;
	}
	RE(i, nax) ile[i] *= (ll) i;
	
	RI(i, nax - 2)
		t[i] = max(t[  (i-2 >= 0) ? (i-2) : 0  ], t[  (i-3 >= 0) ? (i-3) : 0  ]) + ile[i];
	
	ll res = max(t[nax-2], t[nax-3]);
	cout << res;
	return 0;
}