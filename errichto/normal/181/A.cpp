#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

char sl[105];
int anty_x[105], anty_y[105];

int main()
{
	ios_base :: sync_with_stdio(0);
	
	int h, w;
	cin >> h >> w;
	RE(y, h) {
		cin >> sl;
		RE(x, w) if(sl[x] == '*') {
			anty_x[x]++;
			anty_y[y]++;
		}
	}
	RE(y, h) if(anty_y[y] == 1) cout << y + 1 << " ";
	RE(x, w) if(anty_x[x] == 1) cout << x + 1;

	return 0;
}