#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

struct trie {
    trie* children[2];
    int cnt, val;

    trie() : cnt(0), val(0) {
        for(int i=0; i<2; i++)
            children[i] = NULL;
    }

    void add(string &word, int v, int pos = 0) {
        cnt++;
        if(pos == word.size()) {
            val = v;
            return;
        }

        int nxt = word[pos] - '0';
        if(children[nxt] == NULL) children[nxt] = new trie();
        children[nxt]->add(word, v, pos + 1);
    }

    int best(string &word, int v, int pos = 0) {
        if(pos == word.size()) {
            cnt--;
            return v ^ val;
        }

        int nxt = word[pos] - '0';
        if(children[nxt] && children[nxt]->cnt > 0) {
            cnt--;
            return children[nxt]->best(word, v, pos + 1);
        }

        else {
            cnt--;
            return children[nxt ^ 1]->best(word, v, pos + 1);
        }
    }
} dict;

ll n, a[MN], p;
string A[MN], P;

vector<ll> res;

string to_str(int x) {
    string ret = "";
    for(int i = 0; i < 30; i++) {
        ret += (x % 2) ? "1" : "0";
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    scanf("%lld", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &p);
        P = to_str(p);

        dict.add(P, p);
    }

    for(int i=0; i<n; i++) {
        A[i] = to_str(a[i]);
        res.push_back(dict.best(A[i], a[i]));
    }

    for(ll x : res) {
      printf("%lld ", x);
    }
    return 0;
}