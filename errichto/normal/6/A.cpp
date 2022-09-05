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

int t[4];

int main()
{
	ios_base::sync_with_stdio(0);
	RE(i, 4) cin >> t[i];
	sort(t, t + 4);
	RE(i, 4) RE(j, i) RE(k, j) if(t[k] + t[j] > t[i]) {
		cout << "TRIANGLE\n";
		return 0;
	}
	RE(i, 4) RE(j, i) RE(k, j) if(t[k] + t[j] == t[i]) {
		cout << "SEGMENT\n";
		return 0;
	}
	cout << "IMPOSSIBLE\n";	
	return 0;
}