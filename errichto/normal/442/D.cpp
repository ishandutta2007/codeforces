#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

int ojc[nax];
int res[nax];
int a[nax], b[nax];

int badaj(int n) {
	RI(i, n) a[i] = b[i] = 0;
	for(int i = n; i > 1; --i) {
		int x = max(a[i], b[i] + 1), o = ojc[i];
		if(x > a[o]) {
			b[o] = a[o];
			a[o] = x;
		}
		else maxi(b[o], x);
	}
	return a[1];
}

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	RI(i, n) cin >> ojc[i + 1];
	n++;
	res[1] = res[2] = 1;
	res[n] = badaj(n);
	vector<pii > w;
	w.pb(mp(2, n));
	for(int i = 0; i < w.size(); ++i) {
		int low = w[i].st;
		int high = w[i].nd;
		if(res[low] == res[high])
			for(int j = low; j <= high; ++j)
				res[j] = res[low];
		else if(high - low > 1) {
			int med = (low + high) / 2;
			res[med] = badaj(med);
			w.pb(mp(low, med));
			w.pb(mp(med, high));
		}
	}
	for(int i = 2; i <= n; ++i) cout << res[i] << " ";
	return 0;
}