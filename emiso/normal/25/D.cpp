#include <bits/stdc++.h>
#define MN 1010

using namespace std;

int rnk[MN], parent[MN];

int read(int a) {
    if(a == parent[a]) return a;
    return parent[a] = read(parent[a]);
}

bool merge(int a, int b) {
    a = read(a); b = read(b);
    if(a == b) return false;

    if(rnk[a] > rnk[b]) {
        rnk[a] += rnk[b];
        parent[b] = a;
    }
    else {
        rnk[b] += rnk[a];
        parent[a] = b;
    }

    return true;
}

int a, b, n;
vector<pair<int, int> > superfluous;

int main() {
    scanf("%d", &n);

    for(int i=0; i<=n; i++) {
        rnk[i] = 1;
        parent[i] = i;
    }

    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        if(!merge(a, b)) {
            superfluous.push_back({a, b});
        }
    }

    if(superfluous.empty()) printf("0\n");
    else {
        printf("%d\n", superfluous.size());

        int id = 2;
        while(!superfluous.empty()) {
            if(merge(1, id)) {
                printf("%d %d 1 %d\n", superfluous.back().first, superfluous.back().second, id);
                superfluous.pop_back();
            }
            id++;
        }
    }

    return 0;
}