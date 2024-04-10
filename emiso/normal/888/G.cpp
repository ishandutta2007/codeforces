#include <bits/stdc++.h>

using namespace std;

int n, a[200020];

struct trie {
    int val;
    trie* ch[2];

    trie() {
        val = 0;
        ch[0] = ch[1] = nullptr;
    }

    void add(int x, int b = 30) {
        if(b < 0) {
            val = x;
            return;
        }
        int nxt = (x & (1 << b)) > 0;
        if(ch[nxt] == nullptr) ch[nxt] = new trie();
        ch[nxt]->add(x, b - 1);
    }
    int query_min(int y, int b = 30) {
        if(b < 0) return val ^ y;
        int nxt = (y & (1 << b)) > 0;
        if(ch[nxt] == nullptr) nxt ^= 1;
        return ch[nxt]->query_min(y, b - 1);
    }

    void for_all_aux(vector<int>& ret, int b = 30) {
        if(b < 0) ret.push_back(val);
        else {
            if(ch[0] != nullptr) ch[0]->for_all_aux(ret, b - 1);
            if(ch[1] != nullptr) ch[1]->for_all_aux(ret, b - 1);
        }
    }

    vector<int> for_all(int b = 30) {
        vector<int> ret;
        for_all_aux(ret, b);
        return ret;
    }

    long long solve(int b = 30) {
        if(b < 0) return 0;
        long long ret = 0;
        if(ch[0] != nullptr) ret += ch[0]->solve(b - 1);
        if(ch[1] != nullptr) ret += ch[1]->solve(b - 1);
        if(ch[0] != nullptr && ch[1] != nullptr) {
            int mini = INT_MAX;
            for(int x : ch[0]->for_all(b - 1))
                mini = min(mini, ch[1]->query_min(x, b - 1));
            ret += mini;
        }
        return ret;
    }

} dict;

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dict.add(a[i]);
    }

    printf("%lld\n", dict.solve());
    return 0;
}