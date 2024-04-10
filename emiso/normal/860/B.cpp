#include <bits/stdc++.h>

#define MN 70700
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, cnt, eq;
char s[MN]; string st[MN];


struct trie {
    trie* children[10];
    int cnt;

    trie() : cnt(0) {
        for(int i=0; i<10; i++)
            children[i] = NULL;
    }

    void add(string &word, int pos = 0) {
        if(pos == word.size()) {
            cnt++;
            return;
        }

        int nxt = word[pos] - '0';
        if(children[nxt] == NULL) children[nxt] = new trie();
        children[nxt]->add(word, pos + 1);
    }

    int freq(string &word, int pos = 0) {
        if(pos == word.size()) return cnt;

        int nxt = word[pos] - '0';
        if(children[nxt] == NULL) return 0;

        return children[nxt]->freq(word, pos + 1);
    }
} dict;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%s", s); st[i] = s;

        vector<string> sub;
        for(int j = 0; j < 9; j++) {
            string toadd = "";

            for(int k = j; k < 9; k++) {
                toadd += st[i][k];
                sub.push_back(toadd);
            }
        }

        sort(sub.begin(), sub.end());
        sub.resize(unique(sub.begin(), sub.end()) - sub.begin());
        for(string str : sub) {
            dict.add(str);
        }
    }

    vector<string> ans;
    for(int i=0; i<n; i++) {
        vector<string> cand(9);
        bool found = false;

        for(int j=0; j<9; j++) {
            for(int k = 0; j + k < 9; k++) {
                cand[k] += st[i][j + k];

                if(dict.freq(cand[k]) == 1) {
                    ans.push_back(cand[k]);

                    found = true;
                    break;
                }
            }
            if(found) break;
            cand.pop_back();
        }
    }


    for(string str : ans) {
        printf("%s\n", str.c_str());
    }
    return 0;
}