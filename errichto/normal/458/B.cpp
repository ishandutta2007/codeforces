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
ll INF;

ll t1[nax], t2[nax];

ll F(ll a, ll b) {
	//if(a < 0LL || b < 0LL) while(true) cout << "dupa\n";
	if(a < 2LL || b < 2LL) return a*b;
	if(a > INF / b || b > INF / a) return INF;
	//if (a * b < 0LL || a * b > INF) while(true) cout << "dupa\n";
	return a * b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	INF = inf;
	INF /= 3LL;
	INF *= INF;
	ll res = INF;
	
	int d1, d2;
	cin >> d1 >> d2;
	//if(d1 + d2 > 600) while(true) cout << "dupa\n";
	RE(i, d1) cin >> t1[i];
	RE(i, d2) cin >> t2[i];
	
	sort(t1, t1 + d1);
	sort(t2, t2 + d2);
	ll s1 = 0, s2 = 0;
	RE(i, d1) s1 += t1[i];
	RE(i, d2) s2 += t2[i];
	reverse(t1, t1 + d1);
	reverse(t2, t2 + d2);
	ll s = 0;
	RE(a, d1) {
		s += t1[a];
		ll pom = F(a+1, s2) + s1-s;
		//if(pom > INF || pom < 0LL) while(true) cout << "dupa\n";
		mini(res, pom);
	}
	s = 0;
	RE(a, d2) {
		s += t2[a];
		ll pom = F(a+1, s1) + s2-s;
		//ll pom = suma * ((ll)(a+1));//F(a+1, suma);
		//if(pom > INF || pom < 0LL) while(true) cout << "dupa\n";
		mini(res, pom);
	}
	cout << res;
	
	return 0;
}