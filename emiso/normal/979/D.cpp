#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MN 100100

using namespace std;

int q, u, x, k, s, t, in[MN];
vector<int> divi[MN];

void prep() {
    for(int i = 1; i < MN; i++)
        for(int j = i; j < MN; j += i)
            divi[j].push_back(i);
}

struct trie {
    trie* children[2];
    int cnt, val, mini;

    trie() : cnt(0), mini(9999999), val(-2) {
        for(int i=0; i<2; i++)
            children[i] = NULL;
    }

    void add(string &word, int v, int pos = 0) {
        cnt++;
        mini = min(mini, v);

        if(pos == word.size()) {
            val = v;
            return;
        }

        int nxt = word[pos] - '0';
        if(children[nxt] == NULL) children[nxt] = new trie();

        children[nxt]->add(word, v, pos + 1);
    }

    int best(string &word, int v, int limit, int pos = 0) {
        if(pos == word.size()) {
            return val;
        }

        int nxt = word[pos] - '0';

        int ret = -1;
        if(children[nxt ^ 1] && children[nxt ^ 1]->cnt > 0 && children[nxt ^ 1]->mini <= limit) {
            ret = children[nxt ^ 1]->best(word, v, limit, pos + 1);
        }

        if(ret == -1 && children[nxt] && children[nxt]->cnt > 0 && children[nxt]->mini <= limit) {
            ret = children[nxt]->best(word, v, limit, pos + 1);
        }

        return ret;
    }
} dict[MN];

string to_str(int x) {
    string ret = "";
    for(int i = 0; i < 20; i++) {
        ret += (x % 2) ? "1" : "0";
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string str;

int main() {
    prep();
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &u);
            if(in[u]) continue;

            in[u] = 1;
            str = to_str(u);
            for(int &d : divi[u]) {
                dict[d].add(str, u);
            }

        } else if(t == 2) {
            scanf("%d %d %d", &x, &k, &s);
            str = to_str(x);

            int ans = -1;
            for(int &d : divi[x]) {
                if(d % k > 0) continue;

                int z = dict[d].best(str, x, s - x);
                if(z == -1) continue;
                assert(z != -2);

                if(ans == -1) ans = z;
                else if((x ^ ans) < (x ^ z))
                    ans = z;
            }

            printf("%d\n", ans);
        } else assert(false);
    }
    return 0;
}