#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
const int inf=1e9+5, nax=1e6+5, mod=1e9+7;

int t[1005], s[1005];

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	RI(i,n) {
		int p;
		cin >> p;
		t[i] = (mod + 2 + s[i-1] - s[p-1]) % mod;
		s[i] = (s[i-1] + t[i]) % mod;
	}
	cout << s[n];


	return 0;
}