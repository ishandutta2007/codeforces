#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
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
const int pot = 1024 * 128;

int tr[2 * pot + 5], cena_tr[2 * pot + 5];

vi w[nax];
vi odw[nax];

struct cmp {
	bool operator() (int a, int b) {
		if(w[a].size() != w[b].size()) return w[a].size() > w[b].size();
		return a < b;
	}
};

set<int, cmp> s;
vector<pii > in;

int Ile_tr(int x) {
	x += pot;
	int ile = tr[x];
	while(x) {
		if(x%2) ile += tr[x-1];
		x /= 2;
	}
	return ile;
}

int Ile_cena_tr(int x) {
	x += pot;
	int ile = cena_tr[x];
	while(x) {
		if(x%2) ile += cena_tr[x-1];
		x /= 2;
	}
	return ile;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, ja = 0;
	cin >> n;
	RE(i, n) {
		int a, b;
		cin >> a >> b;
		if(a == 0) ja++;
		else
			in.pb(mp(b, a));
			//w[a].pb(b);
	}
	sort(in.begin(), in.end());
	RE(i, in.size()) {
		int money = in[i].st, id = in[i].nd;
		odw[money].pb(i);
		w[id].pb(money);
		cena_tr[pot + i] = money;
	}
	for(int i = pot - 1; i; i--) cena_tr[i] = cena_tr[2*i] + cena_tr[2*i+1];
	RI(i, nax-1) if(!w[i].empty()) {
		s.insert(i);
		sort(w[i].begin(), w[i].end());
		reverse(w[i].begin(), w[i].end());
	}
	s.insert(1);
	int wydany = 0;
	int res = inf;
	while(s.size() > 0 && ja <= (int) w[*s.begin()].size()) {
		int a = *s.begin();
		int chce = w[a].size() - ja + 1; // >= 1
		
		int low = 0, high = nax - 2;
		while(low < high) {
			int med = (low + high) / 2;
			int pom = med + 1 - Ile_tr(med);
			if(pom >= chce) high = med;
			else low = med + 1;
		}
		mini(res, wydany + Ile_cena_tr(low));
		
		s.erase(s.begin());
		int cena = w[a].back();
		wydany += cena;
		w[a].pop_back();
		s.insert(a);
		ja++;
		
		int id = odw[cena].back();
		odw[cena].pop_back();
		for(int i = pot + id; i; i/=2) {
			tr[i]++;
			cena_tr[i] -= cena;
		}
		
	}
	cout << min(res, wydany);
	
	return 0;
}