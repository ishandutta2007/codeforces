#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
const int inf=1e9+5, nax=100321, mod=1e9+7;

int NT[nax][102];
int in[nax];
int roz[102];

vector<pii > w[nax];

int main()
{
	ios_base::sync_with_stdio(0);

	RE(i,nax) NT[i][0] = 1;
	RE(i,102) NT[i][i] = 1;
	RE(i,nax) RI(j,min(101,i-1))
		NT[i][j] = (NT[i-1][j] + NT[i-1][j-1]) % mod;

	int n, z;
	cin >> n >> z;
	RI(i,n) cin >> in[i];
	RI(i,z) {
		int l, r, k;
		cin >> l >> r >> k;
		w[l].pb(mp(k,k));
		w[r+1].pb(mp(k+r+1-l,k-inf));
	}

	RI(i, n) {
		for(int j = 100; j >= 0; --j) roz[j] = (roz[j]+roz[j+1]) % mod;
		RE(coko, w[i].size()) {
			pii p = w[i][coko];
			if (p.nd >= 0) {
				for(int j = 0; p.nd >= 0; ++j) {
					roz[j] = (roz[j] + NT[p.st][p.nd]) % mod;
					p.st--;
					p.nd--;
				}
			}
			else {
				p.nd += inf;
				for(int j = 0; p.nd >= 0; ++j) {
					roz[j] = (mod + roz[j] - NT[p.st][p.nd]) % mod;
					p.st--;
					p.nd--;
				}
			}
		}
		cout << (in[i] + roz[0]) % mod << " ";
	}

	return 0;
}