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
const int inf=1e9+5, nax=1e6+5;

int t[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	RE(i, n) cin >> t[i];
	int poz = 0;
	while (poz + 1 < n && t[poz + 1] >= t[poz]) poz++;
	int memo = poz;
	poz++;
	while (poz + 1 < n && t[poz + 1] >= t[poz]) poz++;
	if(memo == n-1 || (t[n-1] <= t[0] && poz == n-1)) cout << n - 1 - memo;
	else cout << "-1";
	
	return 0;
}