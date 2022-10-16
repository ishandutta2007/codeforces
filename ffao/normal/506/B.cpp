#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

const int NMAX = 100005;
int n, m, ccnt;
vector<int> G[NMAX], Grev[NMAX];
bool foi[NMAX];
int par[NMAX];
bool loaded[NMAX];

int root(int a) {
    if (par[a] == a) return a;
    return par[a] = root(par[a]);
}

void join(int a, int b) {
    a = root(a), b = root(b);
    par[b] = a;
    loaded[a] |= loaded[b];
}

stack<int> P;
vector<int> V;
int ans = 0;

void dfs(int i){
    foi[i] = true;
    for (int j : G[i])
        if (!foi[j])
            dfs(j);
    P.push(i);
}

void dfsT(int i){
    foi[i] = true;
    V.push_back(i);
    for(int j : Grev[i])
        if (!foi[j]){
            dfsT(j);
        }
}

void CFC(){
    memset(foi,0,sizeof(foi));
    for(int i=0;i<n;i++)
        if (!foi[i])
            dfs(i);
        memset(foi,0,sizeof(foi));
        while(!P.empty()){
            int u = P.top(); P.pop();
            if (!foi[u]){
                V.clear();
                dfsT(u);

                if (V.size() > 1) loaded[root(u)] = true;
            }
        }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) par[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        G[a].push_back(b);
        Grev[b].push_back(a);
    }

    CFC();

    for (int i = 0; i < n; i++) 
        for (int j : G[i]) 
            join(i, j);

    int ans = n;
    for (int i = 0; i < n; i++) 
        if (par[i] == i) {
            if (!loaded[i]) ans--;
        }

    printf("%d\n", ans);
}