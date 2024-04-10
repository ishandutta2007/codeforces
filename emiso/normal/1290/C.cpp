#include <bits/stdc++.h>

#define MN 300060

using namespace std;
typedef long long ll;

int n, k, pai[2*MN], rnk[2*MN], cost[2*MN], ans, use[2*MN];
char s[MN];
vector<int> lamp[MN];

int read(int x) {
    if(pai[x] == x) return x;
    return pai[x] = read(pai[x]);
}

bool join(int a, int b) {
    a = read(a), b = read(b);
    if(a == b) return false;

    if(rnk[a] < rnk[b]) swap(a, b);

    pai[b] = a;
    if(rnk[b] == rnk[a]) rnk[a]++;
    cost[a] += cost[b];
    use[a] |= use[b];

    return true;
}

int main() {
    scanf("%d %d %s", &n, &k, s);

    for(int i = 0; i < k; i++) {
        int c, x;
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &x);
            lamp[x-1].push_back(i);
        }
    }

    for(int i = 0; i < MN; i++) {
        pai[i] = i;
        rnk[i] = 1;
        cost[i] = 0;

        pai[i+MN] = i+MN;
        rnk[i+MN] = 1;
        cost[i+MN] = 1;
    }


    for(int i = 0; i < n; i++) {
        if(lamp[i].size() == 0);
        else if(lamp[i].size() == 1) {
            int l = lamp[i][0];
            int a = read(l), b = read(l + MN);

            if(s[i] == '0') {
                if(!use[b]) {
                    ans -= min(cost[a], cost[b]);
                    ans += cost[b];
                    use[b] = 1;
                }
            } else {
                if(!use[a]) {
                    ans -= min(cost[a], cost[b]);
                    ans += cost[a];
                    use[a] = 1;
                }
            }
        } else {
            int l1 = lamp[i][0], l2 = lamp[i][1];
            int a = read(l1), b = read(l2), c = read(l1 + MN), d = read(l2 + MN);

            if(s[i] == '1' && a != b) {

                if(use[a]) ans -= cost[a];
                else if(use[c]) ans -= cost[c];
                else ans -= min(cost[a], cost[c]);

                if(use[b]) ans -= cost[b];
                else if(use[d]) ans -= cost[d];
                else ans -= min(cost[b], cost[d]);

                join(a, b);
                join(c, d);

                a = read(a);
                c = read(c);

                if(use[a]) ans += cost[a];
                else if(use[c]) ans += cost[c];
                else ans += min(cost[a], cost[c]);

            } else if(s[i] == '0' && a != d) {

                if(use[a]) ans -= cost[a];
                else if(use[c]) ans -= cost[c];
                else ans -= min(cost[a], cost[c]);

                if(use[b]) ans -= cost[b];
                else if(use[d]) ans -= cost[d];
                else ans -= min(cost[b], cost[d]);

                join(a, d);
                join(b, c);

                a = read(a);
                c = read(c);

                if(use[a]) ans += cost[a];
                else if(use[c]) ans += cost[c];
                else ans += min(cost[a], cost[c]);

            }
        }

        printf("%d\n", ans);
    }

    return 0;
}