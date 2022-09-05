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
const int inf=1e9+5, nax=1e5+5;

const int SZEFUJ = 1, DAJ = 2, PYTAJ = 3;
int rodz[nax], niski[nax], wysoki[nax], kto[nax], nr[nax];
int ojc[nax][20], czas[nax][20];
int h[nax];
vi w[nax];
int L = 1;
int lewy[nax], prawy[nax];
int kiedy[nax];

void dfs(int x) {
	lewy[x] = L++;
	for(auto y : w[x]) {
		h[y] = h[x] + 1;
		dfs(y);
	}
	prawy[x] = L++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, z;
	int licz_pakiety = 0;
	cin >> n >> z;
	RI(i, z) {
		cin >> rodz[i];
		if(rodz[i] == SZEFUJ) {
			cin >> niski[i] >> wysoki[i];
			ojc[ niski[i] ][0] = wysoki[i];
			czas[ niski[i] ][0] = i;
			w[ wysoki[i] ].pb(niski[i]);
		}
		else if(rodz[i] == DAJ) {
			licz_pakiety++;
			cin >> kto[i];
			kiedy[licz_pakiety] = i;
		}
		else cin >> kto[i] >> nr[i];
	}
	RI(i, n) if(ojc[i][0] == 0) w[0].pb(i);
	dfs(0);
	RE(k, 19) RI(i, n) {
		ojc[i][k + 1] = ojc[  ojc[i][k]  ][k];
		czas[i][k + 1] = max(czas[i][k], czas[ ojc[i][k] ][k]);
	}
	RI(i, z) if(rodz[i] == PYTAJ) {
		int v = kto[i], x = nr[i];
		int chwila = kiedy[x];
		int dostal = kto[chwila];
		if(v == dostal) cout << "YES\n";
		else if(lewy[v] < lewy[dostal] && prawy[dostal] < prawy[v]) {
			
			int roz = h[dostal] - h[v];
			int T = 0;
			RE(k, 20) {
				if(roz % 2) {
					maxi(T, czas[dostal][k]);
					dostal = ojc[dostal][k];
				}
				roz /= 2;
			}
			if(T > chwila) cout << "NO\n";
			else cout << "YES\n";
			
		}
		else cout << "NO\n";
	}
	return 0;
}