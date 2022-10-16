/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int dr[10001], dc[10001];
vi row[10001], col[10001];
priority_queue<pii> todo;
vector<pii> lights;
int dist[10001];
map<pii,int> label;
int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};
int n,m,k; 

void filrow(int i, int val){
    if (i >= 1 && i <= n && dr[i] == 0) {
        dr[i] = 1;
        for (int x: row[i]) if (val < dist[x]) {
            dist[x] = val;
            todo.push({-dist[x],x});
        }
    }
}

void filcol(int i, int val) {
    if (i >= 1 && i <= m && dc[i] == 0) {
        dc[i] = 1;
        for (int x: col[i]) if (val < dist[x]) {
            dist[x] = val;
            todo.push({-dist[x],x});
        }
    }
}

void ad(int x, int y, int val) {
    if (label.find({x,y}) != label.end()) 
        if (dist[label[{x,y}]] > val) {
            dist[label[{x,y}]] = val;
            todo.push({-val,label[{x,y}]});
        }
}

int main() {
    cin >> n >> m >> k;
    
    F0R(i,k) {
        int r,c; cin >> r >> c;
        lights.pb({r,c});
        row[r].pb(i);
        col[c].pb(i);
        label[{r,c}] = i;
    }
    
    F0R(i,10001) dist[i] = MOD;
    
    if (label.find({n,m}) == label.end()) {
        filrow(n-1,1);
        filrow(n,1);
        filcol(m-1,1);
        filcol(m,1);
    } else todo.push({0,label[{n,m}]});
    
    
    while (todo.size()) {
        auto a = todo.top(); todo.pop();
        a.f = -a.f;
        if (a.f > dist[a.s]) continue;
        
        F0R(i,4) ad(lights[a.s].f+xdir[i],lights[a.s].s+ydir[i],a.f);
        FOR(i,lights[a.s].f-2,lights[a.s].f+3) filrow(i,a.f+1);
        FOR(i,lights[a.s].s-2,lights[a.s].s+3) filcol(i,a.f+1);
    }
    
    if (dist[0] != MOD) cout << dist[0];
    else cout << -1;
}