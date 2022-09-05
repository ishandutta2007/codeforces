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
const int inf=1e9+5, nax=1e6+5;

int n, w, m;
int t[nax], anty[nax];

bool check(int res) {
	RI(i, n) anty[i] = 0;
	int s = 0, ile = 0;
	RI(i, n) {
		s -= anty[i];
		if(t[i] + s < res) {
			int trzeba = res - (t[i] + s);
			s += trzeba;
			ile += trzeba;
			if(i + w <= n)
				anty[i + w] = trzeba;
		}
		if(ile > m) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> w;
	int najm = inf;
	RI(i, n) {
		cin >> t[i];
		mini(najm, t[i]);
	}
	int low = najm, high = najm + m;
	while(low != high) {
		int med = (low + high + 1) / 2;
		if(check(med)) low = med;
		else high = med - 1;
	}
	cout << low;
	return 0;
}