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
#define x first
#define y second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;
const double PI = acos(0) * 2.0;

int C(char a) {
	return (int) ( a - '0' );
}

char sl[6];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> sl;
	double h = C(sl[0]) * 10 + C(sl[1]);
	double m = C(sl[3]) * 10 + C(sl[4]);
	if(h > 11.5) h -= 12.0;
	h *= 360.0 / 12.0;
	m *= 360.0 / 60.0;
	h += m / 12.0;
	cout << h << " " << m << "\n";
	return 0;
}