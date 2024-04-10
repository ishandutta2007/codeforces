#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int flag = 1, visit[110], sz[110], ans = 1, c[110];

int lcm(int a, int b) {
    return a / __gcd(a,b) * b;
}

int dfs(int node, int dist) {
    if(visit[node] == 2) return dist;
    visit[node]++;

    dfs(c[node], dist + 1);
}

int main() {
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++) {
        scanf("%d",&c[i]);
    }

    for(int i=1;i<=n;i++) {
        if(visit[i] == 0) {
            int ciclosize = dfs(i, 0) / 2;
            //printf("%d %d\n", i, ciclosize);
            if(ciclosize % 2 == 0) ciclosize /= 2;
            ans = lcm(ans, ciclosize);
        }
        if(visit[i] == 1) {
            flag = 0;
            break;
        }
    }

    for(int i=1;i<=n;i++) {
        if(visit[i] == 1) {
            flag = 0;
            break;
        }
    }

    if(!flag) printf("-1");
    else printf("%d\n", ans);
    return 0;
}