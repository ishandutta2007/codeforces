#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>
#include <queue>

using namespace std;

#define pb push_back
typedef vector<int> vi;
typedef queue<int> qi;

const int MAXN = 2e3 + 100;
const int INF = 1e9 + 1e6;

struct COL {
public:
    int c;
    int rl, rm;     //both inclusive
    COL(int a = -1, int b = 0, int d = 0) {c = a, rl = b, rm = d;}
} col[MAXN*MAXN];
int cols;

int N, M;
bool grid[MAXN][MAXN];
int R, C, X, Y;

int grp[MAXN][MAXN];

vi adj[MAXN * MAXN];
int dst[MAXN * MAXN];
bool vis[MAXN * MAXN];

int main() {
    scanf("%d%d", &N, &M);
    scanf("%d%d%d%d", &R, &C, &X, &Y);
    
    char in;
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) {
        scanf(" %c", &in);
        grid[i][j] = (in == '.');
    }
    
    for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) grp[i][j] = -1;
    
    cols = 0;
    for(int c = 0;c < M;c++) {
        for(int i = 0, j;i < N;i = j) {
            if(!grid[i][c]) {
                j = i + 1;
                continue;
            }
            
            assert(grid[i][c]);
            col[cols] = COL(c, i, i);
            for(j = i;j < N and grid[j][c];j++) {
                col[cols].rm = j;
                grp[j][c] = cols;
                if(c > 0) if(grp[j][c - 1] != -1 and (adj[cols].size() == 0 or adj[cols][adj[cols].size()-1] != grp[j][c - 1])) {
                    adj[cols].pb(grp[j][c - 1]);
                    adj[grp[j][c - 1]].pb(cols);
                }
            }
            cols++;
        }
    }
    
    /*
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            printf("%d ", grp[i][j]);
        }
        cout << '\n';
    }
    //*/
    /*
    for(int i = 0;i < cols;i++) {
        printf("%d: ", i);
        for(int j = 0;j < adj[i].size();j++) printf("%d ", adj[i][j]);
        printf("\n");
    }
    //*/
    
    for(int i = 0;i < cols;i++) dst[i] = INF, vis[i] = false;
    
    qi qu;
    qu.push(grp[R - 1][C - 1]);
    dst[grp[R - 1][C - 1]] = 0;
    while(!qu.empty()) {
        int n = qu.front();
        qu.pop();
        vis[n] = true;
        for(int i = 0;i < adj[n].size();i++) {
            if(vis[adj[n][i]]) continue;
            if(dst[n] + 1 < dst[adj[n][i]]) {
                dst[adj[n][i]] = dst[n] + 1;
                vis[adj[n][i]] = true;
                qu.push(adj[n][i]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0;i < cols;i++) {
        int sm = dst[i];                //r + l = sm
        int dif = (col[i].c - (C - 1));   //r - l = dif
        
        //assert(!((sm+dif)&1));
        
        int l = (sm - dif)/2;
        int r = (sm + dif)/2;
        
        if(l <= X and r <= Y) ans += col[i].rm - col[i].rl + 1;
    }
    
    printf("%d\n", ans);
    
    return 0;
}