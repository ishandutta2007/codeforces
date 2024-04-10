#include <iostream>
#include <cstdio>

#include <vector>
#include <map>
#include <utility>
#include <cassert>
#include <algorithm>
#include <ctime>

using namespace std;

const int PI = 80000;
int P[PI];
const int Ps = 7;
int ps;

typedef vector<int> vi;
#define pb push_back
typedef map<vi, int> mapv;
typedef pair<vi, int> pvi;
#define mp make_pair

void pout(const vi& a) {
    for(int i = 0;i < a.size();i++) cerr << a[i] << " ";
    cerr << "\n";
}

const int MAXN = 300;
int d[MAXN][MAXN];
mapv id;
int ctr;
const int MAXA = 9;
const int INF = 1e9 + 1e6;
const int MAXV = 1e6;

typedef long long ll;
typedef map<ll, int> mapli;

mapli dist[MAXN];
mapli dist2[MAXN];

int ans[MAXN][MAXN];

int a[Ps];
void bfs(const int& c, const int& p, const int& ds, const ll& v) {
    if(c == Ps) {
        if(ds <= MAXA/2) {
            if(dist2[ctr].find(v) == dist2[ctr].end()) dist2[ctr].insert(mp(v, ds));
            else {
                int &t = dist2[ctr][v];
                if(ds < t) t = ds;
            }
        }
        if(dist[ctr].find(v) == dist[ctr].end()) dist[ctr].insert(mp(v, ds));
        else {
            int &t = dist[ctr][v];
            if(ds < t) t = ds;
        }
        return;
    }
    for(int i = 0;i <= p;i++) {
        int nd = ds + abs(a[c] - i);
        if(nd > MAXA) continue;
        bfs(c + 1, i, nd, v * (i + 1));
    }
}

void gen(const int& c, const int& p, int v) {
    if(c == Ps) {
        bfs(0, 50, 0, 1);
        
        vi cur(0, 0);
        for(int i = 0;i < c;i++) if(a[i]) cur.pb(a[i]);
        
        assert(id.find(cur) == id.end());
        
        id.insert(mp(cur, ctr++));
        
        return;
    }
    for(int i = 0;i <= p;i++) {
        a[c] = i;
        gen(c + 1, i, v);
        v /= P[c];
        if(v == 0) break;
    }
}

int tid[MAXV + 100];
int T, A, B;
int f[MAXV + 100], ft[MAXV + 100];

vi factor(int n) {
    vi ret(0, 0);
    int pr = -1;
    while(n > 1) {
        if(f[n] == f[pr]) ret.back()++;
        else ret.pb(1);
        pr = n, n = ft[n];
    }
    if(!ret.empty()) sort(ret.begin(), ret.end(), [](const int& a, const int& b){return a > b;});
    return ret;
}

int main() {
    clock_t timer = clock();
    
    ps = 0;
    P[ps++] = 2;
    P[ps++] = 3;
    for(int i = 5;i <= MAXV;i += 2) {
        bool prm = true;
        for(int j = 0;j < ps and P[j]*P[j] <= i;j++) {
            if(i%P[j] == 0) {prm = false; break;}
        }
        if(prm) P[ps++] = i;
    }
    //cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << "\n";
    
    ctr = 0;
    gen(0, 20, MAXV);
    
    for(int i = 0;i <= ctr;i++) for(int j = 0;j <= ctr;j++) ans[i][j] = INF;
    for(int i = 0;i < ctr;i++) {
        for(int j = 0;j < ctr;j++) {
            for(auto k : dist2[i]) {
                mapli::iterator t;
                if((t = dist[j].find(k.first)) != dist[j].end()) ans[i][j] = ans[j][i] = min(ans[i][j], k.second + t->second);
            }
        }
    }
    //cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << "\n";
    
    for(int i = 0;i <= MAXV;i++) f[i] = ft[i] = -1;
    for(int i = ps-1;i >= 0;i--) {
        for(int j = P[i];j <= MAXV;j += P[i]) if(f[j] == -1) f[j] = P[i], ft[j] = j/P[i];
    }
    //cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << "\n";
    /*
    for(int i = 1;i <= MAXV;i++) {
        tid[i] = id[factor(i)];
    }
    cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << "\n";
    */
    
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &A, &B);
        //printf("%d\n", ans[tid[A]][tid[B]]);
        printf("%d\n", ans[id[factor(A)]][id[factor(B)]]);
    }
    
    cerr << (clock() - timer) * 1.0/CLOCKS_PER_SEC << "\n";
    
    //cerr << ft[12] << "\n";
    //pout(factor(12));
    
    return 0;
}