#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<set>
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
const int inf=1e9+5, nax=1e5+5;
#define vii vector<pii >
const int pot = 512 * 1024;

int n;
pii a[nax];
int RES;

void Wczytaj() {
	cin >> n;
	//n = 20123;;
	set<int> sx, sy;
	RI(i, n) {
		cin >> a[i].x >> a[i].y;
		//a[i].x = (-(int)1e9) + rand() % ((int)2e9);
		//a[i].y = (-(int)1e9) + rand() % ((int)2e9);
		RE(j, 3) {
			sx.insert(a[i].x + j - 1);
			sy.insert(a[i].y + j - 1);
		}
	}
	vi wx, wy;
	for(auto a : sx) wx.pb(a);
	for(auto a : sy) wy.pb(a);
	unordered_map<int, int> odwx, odwy;
	RE(i, wx.size()) odwx[ wx[i] ] = i;
	RE(i, wy.size()) odwy[ wy[i] ] = i;
	RI(i, n) {
		a[i].x = odwx[ a[i].x ] + 5;
		a[i].y = odwy[ a[i].y ] + 5;
	}
}

struct zbior {
	set<int> pus_x, pus_y;
	unordered_map<int, int> mx, my;
	set<pii > sx, sy; // sy ma odwrocone!
	int razem;

	void Zacznij(vii w) {
		razem = w.size();
		for(auto p : w) {
			sx.insert(p);
			sy.insert(mp(p.y, p.x));
			
			pus_x.insert(p.x + 1);
			pus_x.insert(p.x - 1);
			pus_y.insert(p.y + 1);
			pus_y.insert(p.y - 1);
		}
		for(auto p : w) {
			pus_x.erase(p.x);
			pus_y.erase(p.y);
		}
		for(auto p : w) {
			for(int a = p.x + pot; a > 0; a /= 2)
				mx[a]++;
			for(int a = p.y + pot; a > 0; a /= 2)
				my[a]++;
		}
		
		bool flaga = true;
		while(flaga) {
			if(Probujx()){}
			else if(Probujy()){}
			else {
				flaga = false;
				RES++;
			}
		}
	}
	
	int IleDox(int a) {
		a += pot;
		int licz = mx[a];
		while(a) {
			if(a % 2) licz += mx[a - 1];
			a /= 2;
		}
		return licz;
	}
	
	int IleDoy(int a) {
		a += pot;
		int licz = my[a];
		while(a) {
			if(a % 2) licz += my[a - 1];
			a /= 2;
		}
		return licz;
	}
	
	void Usun(pii p) {
		sx.erase(p);
		sy.erase(mp(p.y, p.x));
		for(int a = p.x + pot; a > 0; a /= 2)
			mx[a]--;
		for(int a = p.y + pot; a > 0; a /= 2)
			my[a]--;
		if(mx[p.x + pot] == 0) pus_x.insert(p.x);
		if(my[p.y + pot] == 0) pus_y.insert(p.y);
		razem--;
	}
	
	bool Probujx() {
		if(pus_x.empty()) return false;
		int a = * (pus_x.begin());
		pus_x.erase(pus_x.begin());
		
		if(  (*(sx.begin())).x > a) return true;
		set<pii > :: iterator heh = sx.end();
		heh--;
		if( (*heh).x < a) return true;
		
		int lewo = IleDox(a);
		int prawo = razem - lewo;
		
		vii kol;
		
		if(lewo < prawo) {
			while((!sx.empty()) && (*(sx.begin())).x < a) {
				pii p = *sx.begin();
				Usun(p);
				kol.pb(p);
			}
		}
		else {
			bool flaga = true;
			while((!sx.empty()) && flaga) {
				set<pii > :: iterator it = sx.end();
				it--;
				if((*it).x < a) flaga = false;
				else {
					pii p = *it;
					// it sie zniszczy?
					Usun(p);
					kol.pb(p);
				}
			}
		}
		zbior A;
		A.Zacznij(kol);
		
		return true;
	}
	
	bool Probujy() {
		if(pus_y.empty()) return false;
		int a = * (pus_y.begin());
		pus_y.erase(pus_y.begin());
		
		if(   (*(sy.begin())).x > a)
			return true;
		
		set<pii > :: iterator heh = sy.end();
		heh--;
		if( (*heh).x < a )
			return true;
		
		int gora = IleDoy(a);
		int dol = razem - gora;
		
		
		vii kol;
		
		if(gora < dol) {
			while((!sy.empty()) && (*(sy.begin())).x < a) {
				pii p = *sy.begin();
				p = mp(p.y, p.x);
				Usun(p);
				kol.pb(p);
			}
		}
		else {
			bool flaga = true;
			while((!sy.empty()) && flaga) {
				set<pii > :: iterator it = sy.end();
				it--;
				if((*it).x < a) flaga = false;
				else {
					pii p = *it;
					// it sie zniszczy?
					p = mp(p.y, p.x);
					Usun(p);
					kol.pb(p);
				}
			}
		}
		zbior A;
		A.Zacznij(kol);
		
		return true;
	}
	
};

int main()
{
	ios_base::sync_with_stdio(0);
	srand(0);
	
	Wczytaj();
	vii kol;
	RI(i, n) kol.pb(mp(a[i].x, a[i].y));
	//RI(i, n) cout << a[i].x << " " << a[i].y << "\n";
	
	zbior a;
	a.Zacznij(kol);
	cout << RES;
	
	return 0;
}