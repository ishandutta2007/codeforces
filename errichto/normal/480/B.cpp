#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define RI(i,n) for(int i = 1, _n = (n); i <= _n; ++i)
const int inf = 1e9 + 5, nax = 1e6 + 5;

int t[nax];
set<int> s;

int main()
{
	ios_base :: sync_with_stdio(false);
	
	int n;
	cin >> n;
	int L;
	cin >> L;
	int ania, bartek;
	cin >> ania >> bartek;
	bool an, ba;
	an = ba = false;
	RE(i, n) {
		cin >> t[i];
		s.insert(t[i]);
	}
	RE(i, n) {
		if(s.find(t[i] + ania) != s.end()) an = true;
		if(s.find(t[i] +bartek) != s.end()) ba = true;
	}
	if(an && ba) {
		cout << 0;
		return 0;
	}
	
	if(an) {
		cout << 1 << "\n";
		cout << bartek;
		return 0;
	}
	if(ba) {
		cout << 1 << "\n";
		cout << ania;
		return 0;
	}
	
	RE(i, n) {
		if(t[i] + ania <= L && (  s.find(t[i] + ania + bartek) != s.end() || s.find(t[i] + ania - bartek) != s.end()  )) {
			cout << 1 << "\n";
			cout << t[i] + ania;
			return 0;
		}
		if(t[i] - ania > 0 && (  s.find(t[i] - ania + bartek) != s.end() || s.find(t[i] - ania - bartek) != s.end()  )) {
			cout << 1 << "\n";
			cout << t[i] - ania;
			return 0;
		}
	}
	cout << 2 << "\n" << ania << " " << bartek;
	
	
	return 0;
}