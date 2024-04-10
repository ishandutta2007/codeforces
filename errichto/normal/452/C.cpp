#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
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
const int inf=1e9+5, nax=1e6+5;



int main()
{
	ios_base::sync_with_stdio(0);
	
	ld n, m;
	cin >> n >> m;
	if(n + m < 2.5L) {
		cout << 1;
		return 0;
	}
	ld jeden = 1;
	ld res = jeden / n + (n-jeden) * (m - jeden) / n / (n * m - jeden);
	cout << setprecision(15) << res;
	
	return 0;
}