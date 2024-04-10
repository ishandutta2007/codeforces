#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int N = 444;
int a[N][N];
char e[N][N];

int main(){

    int n = nxt();
    int m = nxt();
    for (int i = 0; i < m; i++){
        int u = nxt(), v = nxt();
        e[u - 1][v - 1] = e[v - 1][u - 1] = 1;
    }
    char qw = e[0][n - 1];
    queue<int> q;
    vector<char> used(n);
    used[0] = 1;
    q.push(0);
    vector<int> dist(n);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++){
            if (e[v][i] != qw && !used[i]){
                used[i] = 1;
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }
    if (!used[n - 1])
        puts("-1");
    else
        printf("%d\n", dist[n - 1]);

    return 0;
}