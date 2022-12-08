#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

#define pb push_back

typedef vector<int> vi;

const int MAXN = 1010000;

int N, M;

vi ans;
vi adj[MAXN];
bool r[MAXN], c[MAXN];
int iot[MAXN], iotl;

int main() {
    scanf("%d%d", &N, &M);
    
    iotl = 0;
    for(int i = 1;i <= N;i++) {
        r[i] = false;
        c[i] = false;
    }
    
    for(int i = 0;i < M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
    }
    
    for(int i = 1;i <= N;i++) {
        if(r[i]) continue;
        iot[iotl++] = i;
        r[i] = true;
        for(int j = 0;j < adj[i].size();j++) {
            if(!r[adj[i][j]]) r[adj[i][j]] = true;
        }
    }
    for(int i = iotl - 1;i >= 0;i--) {
        if(!c[iot[i]]) {
            ans.pb(iot[i]);
            for(int j = 0;j < adj[iot[i]].size();j++) c[adj[iot[i]][j]] = true;
        }
    }
    
    printf("%d\n", static_cast<int> (ans.size()));
    for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}