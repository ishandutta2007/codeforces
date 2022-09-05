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
const int small_inf=2e9+5, nax=3e6+5;
const ll inf = ((ll)small_inf) * small_inf;

struct P
{
	ll cost;
	ll count_mon;
	int ile;
	int mask;
};

vector<P> w;

int fr_size, pr_size;
ll mon_cost;

ll res[nax], RES;

bool cmp(P a, P b) {
	if(a.count_mon != b.count_mon) return a.count_mon < b.count_mon;
	return a.mask < b.mask;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> fr_size >> pr_size >> mon_cost;
	
	RE(i, fr_size) {
		P a;
		cin >> a.cost >> a.count_mon >> a.ile;
		a.mask = 0;
		RE(_, a.ile) {
			int b;
			cin >> b;
			a.mask += (1<<(b-1));
		}
		w.pb(a);
	}
	
	sort(w.begin(), w.end(), cmp);
	
	int M = 1<<(pr_size);
	RES = inf;
	RE(i, M) res[i] = inf;
	res[0] = 0LL;
	RE(i, w.size()) {
		P a = w[i];
		RE(mask, M) if(res[mask] < inf) {
			int pom = mask | a.mask;
			mini(res[pom], res[mask] + a.cost);
		}
		mini(RES, res[M-1] + mon_cost * a.count_mon);
	}
	if(RES == inf) RES = -1;
	cout << RES;
	return 0;
}