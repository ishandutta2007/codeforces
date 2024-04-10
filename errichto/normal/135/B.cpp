#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

pii p[8];
bool jest[8];
int ile;
bool znalezione = false;

int Kw(int a) {
	return a * a;
}

void Odejmij(pii & a, pii b) {
	a.x -= b.x;
	a.y -= b.y;
}

int Odl(pii a, pii b) {
	Odejmij(b, a);
	return Kw(b.x) + Kw(b.y);
}

int Sprawdz(vector<pii > w) {
	RI(i, 3) Odejmij(w[i], w[0]);
	int wart = 0, dal = 0;
	vi kol;
	RI(i, 3) {
		int pom = Kw(w[i].x) + Kw(w[i].y);
		kol.pb(pom);
		if(pom > wart) {
			wart = pom;
			dal = i;
		}
	}
	// dal to najdalszy
	swap(w[dal], w[3]);
	// 3 to najdalszy
	sort(kol.begin(), kol.end());
	if(w[1].x * w[2].x + w[1].y * w[2].y != 0) return 0;
	Odejmij(w[3], w[2]);
	if(w[1] != w[3]) return 0;
	if(kol[0] == kol[1]) return 2;
	return 1;
}


void F(int poz) {
	if(poz + 4 - ile > 8) return;
	if(znalezione) return;
	if(ile == 4) {
		vector<pii > w;
		RE(i, 8) if(jest[i]) w.pb(p[i]);
		int a = Sprawdz(w);
		if(a == 2) {
			vector<pii > v;
			RE(i, 8) if(!jest[i]) v.pb(p[i]);
			if(Sprawdz(v) > 0) {
				znalezione = true;
				cout << "YES\n";
				RE(i, 8) if(jest[i]) cout << i + 1 << " ";
				cout << "\n";
				RE(i, 8) if(!jest[i]) cout << i + 1 << " ";
			}
		}
		return;
	}
	F(poz + 1);
	jest[poz] = true;
	ile++;
	F(poz + 1);
	jest[poz] = false;
	ile--;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	
	RE(i, 8) cin >> p[i].x >> p[i].y;

	F(0); 
	if(!znalezione) cout << "NO";

	return 0;
}