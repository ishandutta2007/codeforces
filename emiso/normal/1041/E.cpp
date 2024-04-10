#include <bits/stdc++.h>

#define MN 1010

using namespace std;
typedef long long ll;

int n, a, b, dist[MN], pai[MN], fi[MN], ok[MN];
vector<int> inut, imp;

void cant() {
    puts("NO");
    exit(0);
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        if(b != n) cant();
        dist[a]++;
    }

    for(int i = 1; i < n; i++) {
        if(dist[i] == 0) inut.push_back(i);
        else {
            imp.push_back(i);
            ok[i] = 1;
        }
    }

    int node = n;
    for(int i = imp.size()-1; i >= 0; i--) {
        int x = imp[i];

        for(int j = 1; j < dist[x]; j++) {
            if(inut.empty()) cant();
            int y = inut.back(); inut.pop_back();
            if(y > x) cant();
            fi[node] = y;
            pai[y] = node;
            node = fi[node];
        }
        fi[node] = x;
        pai[x] = node;
        node = fi[node];
    }
    if(!inut.empty()) cant();

    puts("YES");
    for(int i = 1; i <= n; i++) {
        if(pai[i]) printf("%d %d\n", i, pai[i]);
    }
    return 0;
}