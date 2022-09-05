#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
const int inf=1e9+5, nax=1e6+5;
const int pot = 128 * 1024;

int tr[2 * pot + 5];
int n;
map<int, long long> M;

int F(int start, int a) { // ostatni dobry
	int x = start + pot;
	while(true) {
		if(x == 1)
			return n;
		if(x % 2 == 1) x /= 2;
		else {
			if(tr[x + 1] % a == 0) x /= 2;
			else {
				x++;
				// w dol
				while(true) {
					if(x >= pot) {
						if(tr[x] % a == 0) x++;
						// x jest zy
						return x - pot - 1;
					}
					if(tr[2 * x] % a == 0) x = 2 * x + 1;
					else x = 2 * x;
				}
			}
		}
	}
}

void Coko(int start) {
	int a = tr[start + pot];
	int pop = start -1 ;
	while(true) {
		int x = F(start, a);
		M[a] += (ll)(x - pop);
		pop = x;
		if(x == n) return;
		a = __gcd(a, tr[pot + x + 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> n;
	RI(i, n)
		cin >> tr[pot + i];
	for(int i = pot - 1; i > 0; --i)
		tr[i] = __gcd(tr[2*i], tr[2 * i + 1]);
	
	RI(start, n) Coko(start);
	
	int q;
	cin >> q;
	while(q--) {
		int a;
		cin >> a;
		cout << M[a] << "\n";
	}
	
	return 0;
}