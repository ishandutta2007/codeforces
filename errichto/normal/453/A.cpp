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

ld powe(ld a, int b) {
	if (b == 0) return 1;
	if (b % 2) return a * powe(a * a, b / 2);
	return powe(a * a, b / 2);
}

ld p[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int szesc, n;
	cin >> szesc >> n;
	
	ld res = 0;
	ld s = 0;
	RI(i, szesc) {
		ld pom = ( (ld) i ) / ( (ld) szesc );
		pom = powe(pom, n);
		pom -= s;
		s += pom;
		p[i] = pom;
		res += ((ld) i) * p[i];
	}
	cout << setprecision(10) << res;
	
	return 0;
}