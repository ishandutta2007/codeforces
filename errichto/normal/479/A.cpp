#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifndef LOK
#define cerr if(0) cout
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5, nax = 1e6 + 5;



int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int res = 0;
	maxi(res, a * b * c);
	maxi(res, a * b + c);
	maxi(res, a * (b + c));
	maxi(res, a + b * c);
	maxi(res, a + b + c);
	maxi(res, (a + b) * c);
	printf("%d\n", res);
	return 0;
}