#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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
const int inf = 1e9 + 5, nax = 2e6 + 5;

bool tak[nax];
int mniejszy[nax];

int main()
{
	ios_base :: sync_with_stdio(false);
	
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		tak[a] = true;
	}
	
	mniejszy[0] = -1;
	RI(i, nax - 1) {
		if(tak[i - 1]) mniejszy[i] = i - 1;
		else mniejszy[i] = mniejszy[i - 1];
	}
	
	int res = 0;
	
	RI(i, nax - 1) if(tak[i])
		for(int j = 2 * i; j < nax; j += i)
			maxi(res, i - (j - mniejszy[j]));
	
	cout << res;
	
	return 0;
}