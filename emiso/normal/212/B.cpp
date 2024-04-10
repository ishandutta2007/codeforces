#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

int q, qry[10100];
gp_hash_table<int, int, chash> imp;
char s[1000100]; string str, s2;
vector<int> occ[26];

int main() {
    scanf("%s %d", s, &q); str = s;

    for(int i = 0; i < str.size(); i++) {
        occ[str[i]-'a'].push_back(i);
    }

    for(int j = 0; j < q; j++) {
        scanf("%s", s); s2 = s;

        int mask = 0;
        for(int i = 0; i < s2.size(); i++)
            mask |= (1 << (s2[i] - 'a'));

        qry[j] = mask;
        imp[mask];
    }

    for(int i = 0; i < str.size(); i++) {
        int eq = -1;
        if(i) eq = str[i-1] - 'a';

        vector<pair<int, int>> oc;
        for(int c = 0; c < 26; c++) {
            int idx = lower_bound(occ[c].begin(), occ[c].end(), i) - occ[c].begin();
            if(idx < occ[c].size()) oc.emplace_back(occ[c][idx], c);
        }
        sort(oc.begin(), oc.end());

        int mask = 0;
        for(auto tt : oc) {
            if(tt.second == eq) break;
            mask |= (1 << tt.second);

            auto x = imp.find(mask);
            if(x != imp.end()) x->second++;
        }
    }

    for(int i = 0; i < q; i++) {
        printf("%d\n", imp[qry[i]]);
    }

    return 0;
}