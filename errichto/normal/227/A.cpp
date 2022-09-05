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

pii t[3];

void Dostosuj(pii p0, pii & p1) {
	p1.x -= p0.x;
	p1.y -= p0.y;
}

const int PROSTO = 0, PRZECIWNIE = 1, ZGODNIE = -1;
int Wek(pii p0, pii p1, pii p2) {
	Dostosuj(p0, p1);
	Dostosuj(p0, p2);
	ll iloczyn = ((ll)p1.x) * p2.y - ((ll)p1.y) * p2.x;
	if(iloczyn == 0) return PROSTO;
	if(iloczyn > 0) return PRZECIWNIE;
	return ZGODNIE;
}

int main()
{
	ios_base::sync_with_stdio(0);
	RE(i, 3) cin >> t[i].x >> t[i].y;
	int a = Wek(t[0], t[1], t[2]);
	if(a == PROSTO) cout << "TOWARDS";
	else if(a == ZGODNIE) cout << "RIGHT";
	else cout << "LEFT";
	cout << "\n";
	
	return 0;
}