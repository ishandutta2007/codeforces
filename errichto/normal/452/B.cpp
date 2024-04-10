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

pii w[4];
vector<pii > a;
int i[4];
pii res[4];

#define R(c) for(i[c] = 0; i[c] < (int) a.size(); ++i[c])

double Odl(pii b, pii c) {
	c.x -= b.x;
	c.y -= b.y;
	return sqrt(double(c.x * c.x + c.y * c.y));
}

bool Ok(pii p) {
	return 0 <= p.x && p.x <= w[0].x &&
		0 <= p.y && p.y <= w[0].y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> w[0].x >> w[0].y;
	w[1].x = w[0].x;
	w[2].y = w[0].y;
	RE(i, 4) {
		for(int xx = -1; xx <= 1; ++xx)
			for(int yy = -1; yy <= 1; ++yy) {
				pii p = mp(w[i].x + xx, w[i].y + yy);
				if(Ok(p)) a.pb(p);
			}
	}
	double best_suma = 0;
	R(0) R(1) R(2) R(3) {
						bool ok = true;
						RE(j, 4) RE(k, j) if(a[i[j]] == a[i[k]]) ok = false;
						if(ok) {
							double suma = 0;
							RE(j, 3) suma += Odl(a[i[j]], a[i[j + 1]]);
							if(suma > best_suma) {
								best_suma = suma;
								RE(j, 4) res[j] = a[i[j]];
							}
						}
	}
	RE(i, 4) cout << res[i].x << " " << res[i].y << "\n";
	
	return 0;
}