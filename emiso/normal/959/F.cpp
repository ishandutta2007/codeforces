#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n, q, x[100010], in[1<<20], ans[100010], val = 1, l, y;
vector<int> inside;
vector<pair<int, int> > queries[100010];

int main() {
    scanf("%d %d", &n, &q);

    in[0] = 1;
    inside.push_back(0);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &l, &y);
        queries[l-1].emplace_back(y, i);
    }
    for(int i = 0; i < n; i++) {
        if(in[x[i]]) {
            val *= 2;
            if(val >= MOD) val -= MOD;
        } else {
            for(int j = inside.size()-1; j >= 0; j--) {
                assert(!in[x[i] ^ inside[j]]);
                in[x[i] ^ inside[j]] = 1;
                inside.push_back(x[i] ^ inside[j]);
            }
        }
        for(auto qry : queries[i]) {
            if(in[qry.first]) ans[qry.second] = val;
            else ans[qry.second] = 0;
        }
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

    return 0;
}