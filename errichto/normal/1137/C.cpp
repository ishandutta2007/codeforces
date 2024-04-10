#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;




// https://github.com/kartikkukreja/blog-codes/blob/master/src/Kosaraju-Sharir%20Algorithm%20for%20SCC.cpp
#define MAXV 100005
using namespace std;

typedef vector <int> vi;

// Assuming vertices are labeled 0...V-1
vi G[MAXV], Grev[MAXV];
bool explored[MAXV];
int leader[MAXV], finish[MAXV], order[MAXV], t = -1, parent = 0, V, E;

// running DFS on the reverse graph
void dfs_reverse(int i) {
    explored[i] = true;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}

// running DFS on the actual graph
void dfs(int i) {
    explored[i] = true;
    leader[i] = parent;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
        if(!explored[*it])
            dfs(*it);
}

// check if u & v are in the same connected component
bool stronglyConnected(int u, int v)    {
    return leader[u] == leader[v];
}











const int nax = 1e5 + 5;
vector<int> edges[nax];
char sl[nax][55];
bool vis[nax][55];
int dp[nax][55];
bool yeah[nax];
int d;
int out[nax];
int answer;
bool done[nax];
vector<int> inv[nax];

void rec(int a) {
    int cc = leader[a];
    debug() << imie(a) imie(cc);
    assert(!done[cc]);
    done[cc] = true;
    vector<pair<int,int>> kol;
    kol.emplace_back(a, 0);
    vis[a][0] = true;
    for(int i = 0; i < (int) kol.size(); ++i) {
        int b = kol[i].first;
        int day = kol[i].second;
        int day2 = day + 1;
        if(day2 == d) {
            day2 = 0;
        }
        for(int c : edges[b]) {
            if(leader[c] == cc && !vis[c][day2]) {
                vis[c][day2] = true;
                kol.emplace_back(c, day2);
            }
        }
    }
    int period = d;
    for(const pair<int,int>& p : kol) {
        if(p.first == a && p.second != 0) {
            period = min(period, p.second);
        }
    }
    for(int shift = 0; shift < period; ++shift) {
        int best = 0;
        
        for(const pair<int,int>& p : kol) {
            int b = p.first;
            int day = p.second + shift;
            if(day >= d) {
                day -= d;
            }
            if(sl[b][day] == '1') {
                yeah[b] = true;
            }
            best = max(best, dp[b][day]);
        }
        for(int x : inv[cc]) {
            if(yeah[x]) {
                ++best;
                yeah[x] = false;
            }
        }
        for(const pair<int,int>& p : kol) {
            int b = p.first;
            int day = p.second + shift;
            if(day >= d) {
                day -= d;
            }
            int prev_day = day - 1;
            if(prev_day == -1) {
                prev_day = d - 1;
            }
            int maybe = best;
            if(b == 0 && day == 0) {
                answer = max(answer, maybe);
            }
            for(int x : Grev[b]) {
                dp[x][prev_day] = max(dp[x][prev_day], maybe);
            }
        }
    }
     
     
     for(int x : inv[cc]) {
         for(int y : Grev[x]) {
             if(leader[x] != leader[y]) {
                 assert(!done[leader[y]]);
                 if(--out[leader[y]] == 0) {
                     rec(y);
                 }
             }
         }
     }
}

int main() {
    int n, m;
    scanf("%d%d%d", &n, &m, &d);
    V = n;
    E = m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        edges[a].push_back(b);
        G[a].push_back(b);
        Grev[b].push_back(a);
    }
    
    for(int i=0; i<V; i++)  {
        if(!explored[i])
            dfs_reverse(i);
        order[finish[i]] = i;
    }
    for(int i = 0; i <= V; ++i) {
        explored[i] = false;
    }
    int countCC = 0;
    for(int i=V-1; i>=0; i--)
        if(!explored[order[i]]) {
            parent = order[i];
            dfs(order[i]);
            countCC++;
        }
    
    for(int a = 0; a < V; ++a) {
        inv[leader[a]].push_back(a);
        debug() << imie(a) imie(leader[a]);
    }
    for(int a = 0; a < n; ++a) {
        scanf("%s", sl[a]);
    }
    
    for(int a = 0; a < n; ++a) {
        for(int b : edges[a]) {
            if(leader[a] != leader[b]) {
                ++out[leader[a]];
            }
        }
    }
    for(int a = 0; a < n; ++a) {
        int cc = leader[a];
        if(!done[cc] && out[cc] == 0) {
            rec(a);
        }
    }
    
    printf("%d\n", answer);
    
    /*vector<pair<int,int>> kol;
    kol.emplace_back(0, 0);
    vis[0][0] = true;
    for(int i = 0; i < (int) kol.size(); ++i) {
        int a = kol[i].first;
        int day = kol[i].second;
        int d2 = day + 1;
        if(d2 == d) {
            d2 = 0;
        }
        for(int b : edges[a]) {
            if(!vis[b][d2]) {
                debug() << imie(a) imie(day) imie(b) imie(d2);
                vis[b][d2] = true;
                kol.emplace_back(b, d2);
            }
        }
    }
    int answer = 0;
    for(int a = 0; a < n; ++a) {
        bool ok = false;
        for(int day = 0; day < d; ++day) {
            if(vis[a][day] && sl[a][day] == '1') {
                ok = true;
            }
        }
        answer += ok;
    }
    printf("%d\n", answer);*/
}