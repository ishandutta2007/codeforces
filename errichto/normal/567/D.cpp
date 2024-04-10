#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int w, n, s; // width, number, size
int t[nax];
bool block[nax];

bool ok() {
	int c = 0;
	
	int prev = 0;
	RI(i, w + 1) {
		if(i == prev + s + 1) {
			++c;
			prev = i;
		}
		if(block[i]) prev = i;
	}
	RI(i, w) block[i] = false;
	return c >= n;
}

int main()
{
	scanf("%d%d%d", &w, &n, &s);
	block[0] = block[w+1] = true;
	int m;
	scanf("%d", &m);
	RI(i, m) {
		scanf("%d", &t[i]);
		block[t[i]] = true;
	}
	if(ok()) {
		puts("-1");
		return 0;
	}
	int low = 1, high = m;
	while(low < high) {
		int med = (low + high) / 2;
		RI(i, med) block[t[i]] = true;
		if(ok()) low = med + 1;
		else high = med;
	}
	printf("%d\n", low);
	
	return 0;
}