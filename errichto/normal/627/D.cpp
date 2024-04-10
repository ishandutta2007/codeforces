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

int n;
bool yes[nax];
vi w[nax];
int value[nax];
int answer;
int subtree[nax];
int sub_yes[nax];

int one(int a, int par) {
	subtree[a] = 1;
	for(int b : w[a]) if(b != par)
		subtree[a] += one(b, a);
	return subtree[a];
}
int two(int a, int par) {
	sub_yes[a] = yes[a];
	for(int b : w[a]) if(b != par)
		sub_yes[a] += two(b, a);
	return sub_yes[a];
}
int dfs(int a, int par) {
	if(!yes[a]) {
		for(int b : w[a]) if(b != par) dfs(b, a);
		return 0;
	}
	int ja = 0;
	int m1 = 0, m2 = 0;
	for(int b : w[a]) if(b != par) {
		int x = dfs(b, a);
		if(sub_yes[b] == subtree[b])
			ja += subtree[b];
		else {
			if(x >= m1) {
				m2 = m1;
				m1 = x;
			}
			else maxi(m2, x);
		}
	}
	int maybe = ja + m1 + m2 + 1;
	maxi(answer, maybe);
	if(n - subtree[a] == sub_yes[1] - sub_yes[a]) {
		//printf("spec %d\n", a);
		maxi(answer, maybe + n - subtree[a]);
	}
	return ja + m1 + 1; // sciezka, licze wierzcholki
}

int bin_ok(int at_least) {
	answer = 0;
	RI(i, n)
		yes[i] = value[i] >= at_least;
	two(1, -1);
	//printf("%d,  %d %d\n", (int)yes[1], subtree[1], sub_yes[1]);
	dfs(1, -1);
	return answer;
}

int main() {
	int k;
	scanf("%d%d", &n, &k);
	RI(i, n) scanf("%d", &value[i]);
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	one(1, -1);
	//printf("%d\n", bin_ok(5));
	int low = 1, high = 1000 * 1000;
	while(low < high) {
		int mid = (low + high + 1) / 2;
		if(bin_ok(mid) >= k) low = mid;
		else high = mid - 1;
	}
	printf("%d\n", low);
	return 0;
}