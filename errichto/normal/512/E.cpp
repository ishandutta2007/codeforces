#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1005;

set<int> s[nax];
bool cel[nax][nax];
set<pii > tera;
vector<pii > res;
int n;
int wynik = 0;

int nast(int a) {
    a++;
    if(a == n+1) a = 1;
    return a;
}

int pop(int a) {
    a--;
    if(a == 0) a = n;
    return a;
}

bool kolej(int a, int b, int c) {
    if(a < c) {
        return a < b && b < c;
    }
    return b > a || b < c;
}

int dupuj(int a, int b) {
    auto it = s[a].find(b);
    ++it;
    if(it == s[a].end()) it = s[a].begin();
    int c = *it;
    if(c == b) return pop(a);
    if(!kolej(b, c, a)) return pop(a);
    return c;
}

int zmiana(pii p) {
    int a = p.st;
    int b = p.nd;
    int c = dupuj(a, b);
    int d = dupuj(b, a);
    int r = 0;
    if(cel[a][b]) r--;
    if(cel[c][d]) r++;
    return r;
}

void rob(pii p) {
    int a = p.st;
    int b = p.nd;
    int c = dupuj(a, b);
    int d = dupuj(b, a);
    s[a].erase(b);
    s[b].erase(a);
    s[c].insert(d);
    s[d].insert(c);
    tera.erase(p);
    tera.insert(mp(c,d));
}

int main(int argc, char *argv[])
{
    debug = argc > 1;
    
    scanf("%d", &n);
    REP(_, n-3) {
        int a, b;
        scanf("%d%d", &a, &b);
        s[a].insert(b);
        s[b].insert(a);
        tera.insert(mp(a,b));
    }
    REP(_, n-3) {
        int a, b;
        scanf("%d%d", &a, &b);
        cel[a][b] = cel[b][a] = true;
    }
    
    for(auto & p : tera) if(!cel[p.st][p.nd]) wynik++;
    
    while(wynik) {
        pii best = *(tera.begin());
        int ziom = zmiana(best);
        int licz = 0;
        for(auto p : tera) {
            int pom = zmiana(p);
            if(pom > ziom || (pom == ziom && rand() % (licz + 5) == 0)) {
                licz++;
                ziom = pom;
                best = p;
            }
        }
        res.pb(best);
        rob(best);
        wynik -= ziom;
    }
    printf("%d\n", (int) res.size());
    for(auto p : res) printf("%d %d\n", p.st, p.nd);
    
    return 0;
}