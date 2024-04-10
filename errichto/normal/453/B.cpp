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
const int inf=1e9+5, nax=105;
const int M = 1024;

vi p;
int rozloz[65];
int in[nax], in0[nax];
pii t[nax][M];
int zamienione[105];

int main()
{
	ios_base::sync_with_stdio(0);
	
	for(int i = 2; i <= 30; ++i) {
		bool ok = true;
		for(int j = 2; j < i; ++j)
			if(i%j == 0) ok = false;
		if(ok)
			p.pb(i);
	}
	
	RI(a, 59) {
		int x = 0;
		RE(i, p.size())
			if(a % p[i] == 0)
				x += (1 << i);
		rozloz[a] = x;
	}
	
	int n;
	cin >> n;
	RE(i, n) {
		cin >> in[i];
		in0[i] = in[i];
	}
	
	if(n==1) {
		cout << in[0];
		return 0;
	}
	
	vi ODP;
	RE(i, n) ODP.pb(1);
	int wart_ODP = 0;
	RE(i, n) wart_ODP += abs(in[i] - 1);
	
	int P = 30;
	
	
	while(true) {
	
				RE(i, n) RE(j, M) t[i][j] = mp(inf, 0);
				
				RI(a, 60) if(a <= 30 || rozloz[a]) t[0][rozloz[a]] = mp(abs(a - in[0]), a);
				
				RI(i, n-1) {
					RE(m, M) RI(a, 60) if(a <= 30 || rozloz[a]) if((m & rozloz[a]) == 0) {
						pii pom;
						pom.st = t[i-1][m].st + abs(in[i] - a);
						pom.nd = a;
						mini(t[i][m | rozloz[a]], pom);
					}
				}
				
				int best = inf, best_m = 0;
				RE(m, M)
					if(t[n-1][m].st < best) {
						best = t[n-1][m].st;
						best_m = m;
					}
				vi odp;
				for(int i = n-1; i >= 0; --i) {
					int a = t[i][best_m].nd;
					odp.pb(a);
					best_m -= rozloz[a];
				}
				reverse(odp.begin(), odp.end());
				RE(i, n) if(zamienione[i])
					odp[i] = zamienione[i];
				int wart = 0;
				RE(i, n) wart += abs(in0[i] - odp[i]);
				
				//if(wart >= wart_ODP)
				
				if(wart < wart_ODP) {
					ODP = odp;
					wart_ODP = wart;
				}
				
				while(true) {
					P++;
					bool pierwsza = true;
					for(int i = 2; i < P; ++i)
						if(P%i == 0) pierwsza = false;
					if(pierwsza) break;
				}
				
				int big_i = 0;
				RE(i, n) if(in[i] > in[big_i]) big_i = i;
				zamienione[big_i] = P;
				in[big_i] = 1;
				
				if (P > 61) break;
	}
	
	RE(i, n)
		cout << ODP[i] << " ";
	//cout << "\n";
	//cout << wart_ODP << "\n";
	
	return 0;
}