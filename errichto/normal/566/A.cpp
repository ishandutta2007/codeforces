#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
#define printf sadf;lkjasPRINTF
#define scanf askdjfa;SCANF

string s[nax];
int d[nax];
int cyfruj(char z) { return z - 'a'; }

ll RES;
int wypisz[nax];

void merge(int a, int b) {
	wypisz[a] = b;
}

vi zosta, zostb;
bool ta[26];
int odw[26];

void rec(vi & A, vi & B, int k) {
	if(A.empty()) {
		for(int b : B) zostb.pb(b);
		return;
	}
	if(B.empty()) {
		for(int a : A) zosta.pb(a);
		return;
	}
	for(int i : A) {
		if(d[i] > k) ta[cyfruj(s[i][k])] = true;
	}
	for(int i : B) {
		if(d[i] > k) ta[cyfruj(s[i][k])] = true;
	}
	int z = 0;
	REP(i, 26) if(ta[i]) {
		odw[i] = z++;
		ta[i] = false;
	}
	vi a[z], b[z];
	int mema = sz(zosta), memb = sz(zostb);
	for(int i : A) {
		if(d[i] > k) a[odw[cyfruj(s[i][k])]].pb(i);
		else zosta.pb(i);
	}
	for(int i : B) {
		if(d[i] > k) b[odw[cyfruj(s[i][k])]].pb(i);
		else zostb.pb(i);
	}
	A.clear();
	B.clear();
	REP(i, z) {
		RES += min(sz(a[i]), sz(b[i]));
		rec(a[i], b[i], k+1);
		a[i].clear();
		b[i].clear();
	}
	while(sz(zosta) > mema && sz(zostb) > memb) {
		merge(zosta.back(), zostb.back());
		zosta.pop_back();
		zostb.pop_back();
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	ios_base :: sync_with_stdio(0);
	
	int n;
	cin >> n;
	RI(i, 2 * n) {
		cin >> s[i];
		d[i] = s[i].length();
	}
	vi a, b;
	RI(i, n) a.pb(i);
	FOR(i,n+1,2*n) b.pb(i);
	vi A, B;
	rec(a,b,0);
	//cout << sz(A) << " " << sz(B) << "\n";
	
	cout << RES << "\n";
	RI(i, n) cout << i << " " << wypisz[i] - n << "\n";
	
	return 0;
}