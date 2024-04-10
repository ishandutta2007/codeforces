#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<ld,ld>
#define mp make_pair
#define x first
#define y second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;
const double PI = acos(0) * 2.0;

int t[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	RE(i, n) {
		cin >> t[i];
		t[i] *= t[i];
	}
	n += 3;
	sort(t, t + n);
	reverse(t, t + n);
	int res = 0;
	for(int i = 0; t[i] > 0; i += 2) {
		res += t[i] - t[i + 1];
	}
	cout << setprecision(10) << PI * ((ld) res);
		
		
	
	return 0;
}