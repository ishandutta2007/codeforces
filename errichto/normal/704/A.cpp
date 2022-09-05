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

int app[nax];
int m[nax];
int pref_read = 0;
int where = 1;
int unread[nax];
int unread_total;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	RI(which, q) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int x;
			scanf("%d", &x);
			app[which] = x;
			++unread[x];
			++unread_total;
		}
		if(type == 2) {
			int x;
			scanf("%d", &x);
			m[x] = which;
			unread_total -= unread[x];
			unread[x] = 0;
		}
		else if(type == 3) {
			int cnt;
			scanf("%d", &cnt);
			while(pref_read < cnt) {
				while(app[where] == 0) ++where;
				if(m[app[where]] < where) {
					unread[app[where]]--;
					unread_total--;
				}
				where++;
				++pref_read;
			}
		}
		printf("%d\n", unread_total);
	}
	return 0;
}