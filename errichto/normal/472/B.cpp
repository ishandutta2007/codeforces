#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
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
#define all(w) w.begin,w.end()
const int inf=1e9+5,nax=1e6+5;

int t[2005];

int main()
{
	ios_base::sync_with_stdio;

	int n, k;
	cin >> n >> k;
	RE(i, n) {
		cin >> t[i];
		t[i]--;
	}
	sort(t, t + n);
	int res = 0;
	RI(f, 2000) {
		int licz = 0;
		RE(i, n) if(t[i] >= f) licz++;
		if(licz > 0) {
			licz--;
			res += 2 * (licz / k) + 1;
		}
	}
	cout << res + t[n - 1];
	return 0;
}