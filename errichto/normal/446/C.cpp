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
const int inf=1e9+5, nax=3e5+5;
const int mod = 1e9 + 9;
const int pot = 1024 * 512;

int f[nax];
int in[nax], s_in[nax];
pii tr2[2 * pot + 5];
int trs[2 * pot + 5];


int F(int i) {
	if(i >= 0) return f[i];
	i = -i;
	if(i % 2 == 0) return mod - f[i];
	return f[i];
}

int FN(int f0, int f1, int n) {
	ll a = f[n + 1];
	a *= (ll) f0;
	a %= (ll) mod;
	ll b = f[n + 2] - 1 + mod;
	b *= (ll) f1;
	b %= (ll) mod;
	return ((int) ( a + b )) % mod;
}

void Dodaj(int a, int b, int x) {
	for(int i = x + pot; i; i /= 2) {
		tr2[i] = mp( (tr2[i].st + a) % mod,  (tr2[i].nd + b) % mod );
		trs[i] = (trs[i] + FN(a, b, x)) % mod;
	}
}

int Query(int x) {
	int res = 0;
	for(int i = x + pot; i; i /= 2)
		if(i % 2 == 0)
			res = (res + FN(tr2[i+1].st, tr2[i+1].nd, x)) % mod;
	for(int i = x + 1 + pot; i; i /= 2)
		if(i % 2)
			res = (res + trs[i-1]) % mod;
	return (res + s_in[x]) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	
	f[1] = 1;
	for(int i = 2; i < nax; ++i)
		f[i] = (f[i-1] + f[i-2]) % mod;
	
	int n, z;
	cin >> n >> z;
	RI(i, n) cin >> in[i];
	RI(i, n) s_in[i] = (s_in[i - 1] + in[i]) % mod;
	
	while(z--) {
		int rodz, left, right;
		cin >> rodz >> left >> right;
		if(rodz == 1) {
			int a = F(1-left), b = F(2-left);
			Dodaj(mod-a, mod-b, left - 1);
			Dodaj(a, b, right);
		}
		else {
			cout << (Query(right) - Query(left-1) + mod) % mod << "\n";
		}
	}
	return 0;
}