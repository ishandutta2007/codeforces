#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define ll long long
#define pb push_back
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

char s[nax];
int n;

bool ok(int x) {
	int akt = 0, M = 0;
	RE(i, n-1) {
		if (s[i] == 'R') akt++;
		else if (akt-1 > -x) akt--;
		maxi(M, akt);
	}
	return M == akt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	n = strlen(s);
	
	if (s[n-1] == 'L') RE(i,n) {
		if (s[i] == 'L') s[i] = 'R';
		else s[i] = 'L';
	}

	if(!ok(1)) cout << "0";
	else if(ok(inf)) cout << "1";
	else {
		int low = 1, high = n+2;
		while (low != high) {
			int med = (low+high+1)/2;
			if (ok(med)) low = med;
			else high = med-1;
		}
		cout << low;
	}
	cout << "\n";
	return 0;
}