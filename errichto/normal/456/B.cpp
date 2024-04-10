#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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

char s[nax];

int P(char a) {
	return (a - '0');
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	int n = strlen(s);
	int x = P(s[n-1]);
	if (n >= 2) x += 10 * P(s[n-2]);
	if (n >= 3) x += 100 * P(s[n-3]);
	int res = 0;
	RI(i, 4) {
		int potega = 1;
		RE(_, x) potega = (potega * i) % 5;
		res += potega;
	}
	res %= 5;
	cout << res;
	return 0;
}