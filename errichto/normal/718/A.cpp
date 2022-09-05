#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
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

int n, t;
char sl[nax];

void biggerInt() {
	int i = 0;
	while(sl[i] != '.') ++i;
	--i;
	int cnt = i;
	while(i >= 0 && sl[i] == '9') {
		sl[i] = '0';
		--i;
	}
	if(i == -1) {
		printf("1");
		REP(_, cnt + 1) printf("0");
		puts("");
	}
	else {
		++sl[i];
		for(int j = 0; sl[j] != '.'; ++j) printf("%c", sl[j]);
		puts("");
	}
	exit(0);
}

int main() {
	scanf("%d%d", &n, &t);
	scanf("%s", sl);
	int i = 0;
	while(sl[i] != '.') ++i;
	++i;
	// first digit
	while(i < n && sl[i] <= '4') ++i;
	if(i == n) {
		while(sl[n-1] == '0') --n;
		if(sl[n-1] == '.') --n;
		REP(i,n) printf("%c", sl[i]); puts("");
		return 0;
	}
	// first digit >= '5'
	while(t-- && '5' <= sl[i] && sl[i] <= '9') {
		mini(n, i);
		--i;
		if(sl[i] == '.') biggerInt();
		if(sl[i] != '9') ++sl[i];
		else {
			while(sl[i] == '9') {
				sl[i] = '0';
				--i;
				if(sl[i] == '.') biggerInt();
			}
		}
	}
	while(sl[n-1] == '0') --n;
	if(sl[n-1] == '.') --n;
	REP(i, n) printf("%c", sl[i]); puts("");
}