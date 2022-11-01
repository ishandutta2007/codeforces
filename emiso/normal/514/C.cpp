#include <bits/stdc++.h>

using namespace std;

struct trie {
    trie* children[3];
    bool ending;

    trie() : ending(false) {
        for(int i=0; i<3; i++)
            children[i] = NULL;
    }

    void add(string &word, int pos = 0) {
        if(pos == word.size()) {
            ending = true;
            return;
        }

        int nxt = word[pos] - 'a';
        if(children[nxt] == NULL) children[nxt] = new trie();
        children[nxt]->add(word, pos + 1);
    }

    bool isWord(string &word, int pos = 0, int error = 0) {
        if(error > 1) return false;
        if(pos == word.size()) return (error == 1 && ending);

        int nxt = word[pos] - 'a';
        bool isIT = false;
        for(int i = 0; i < 3; i++) {
            if(children[i] == NULL) continue;
            if(i == nxt)
                isIT |= children[i]->isWord(word, pos + 1, error);
            else
                isIT |= children[i]->isWord(word, pos + 1, error + 1);
        }

        return isIT;
    }
} mechanism;

char s[600010];
string st;
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        st = s;
        mechanism.add(st);
    }
    for(int i=0; i<m; i++) {
        scanf("%s", s);
        st = s;
        printf("%s\n", (mechanism.isWord(st)) ? "YES" : "NO");
    }
    return 0;
}