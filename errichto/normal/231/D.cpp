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
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

struct P {
	int x;
	int y;
	int z;
	void Wczytaj() {
		cin >> x >> y >> z;
	}
};

P Minus(P a, P b) {
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

int main()
{
	P punkt;
	punkt.Wczytaj();
	P t;
	t.Wczytaj();
	int res = 0;
	int a;

	cin >> a;
	if(punkt.y < 0) res += a;
	cin >> a;
	if(punkt.y > t.y) res += a;

	cin >> a;
	if(punkt.z < 0) res += a;
	cin >> a;
	if(punkt.z > t.z) res += a;

	cin >> a;
	if(punkt.x < 0) res += a;
	cin >> a;
	if(punkt.x > t.x) res += a;

	cout << res;
	
	return 0;
}