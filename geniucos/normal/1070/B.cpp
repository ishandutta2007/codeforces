#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXL = 1000;
const int BITS = 32;

struct Trie {
    bool isBlack;
    bool isWhite;
    bool hasWhite;
    bool hasBlack;

    Trie *son[2];

    Trie() {
        isBlack = isWhite = false;
        hasBlack = hasWhite = false;
        son[0] = son[1] = NULL;
    }
};

char s[1 + MAXL];

void Insert(Trie *root, unsigned int path, int preffix, bool type) {
    Trie *node = root;
    for (int bit = BITS - 1; bit >= BITS - preffix; bit--) {
        int which = 0;
        if (path & (1LL << bit))
            which = 1;
        if (type)
            node->hasWhite = true;
        else
            node->hasBlack = true;
        if (!node->son[which])
            node->son[which] = new Trie();
        node = node->son[which];
    }
    if (type)
        node->hasWhite = node->isWhite = true;
    else
        node->hasBlack = node->isBlack = true;
}

vector<pair<unsigned int, int> > answer;
bool bad = false;

void DFS(Trie *node, unsigned int value, int bits) {
    if (node->isBlack && node->hasWhite)
        bad = true;
    if (node->isWhite && node->hasBlack)
        bad = true;
    if (bad)
        return;
    if (!node->hasWhite) {
        answer.push_back(make_pair(value, bits));
        return;
    }
    if (!node->hasBlack)
        return;
    if (node->son[0])
        DFS(node->son[0], value, bits + 1);
    if (node->son[1])
        DFS(node->son[1], value | (1LL << (BITS - bits - 1)), bits + 1);
}

void Convert(unsigned int value, int preffix) {
    int bit = 31;
    for (int i = 0; i < 4; i++) {
        int x = 0;
        for (int j = 0; j < 8; j++) {
            x *= 2;
            if (value & (1LL << bit))
                x++;
            bit--;
        }
        printf("%d", x);
        if (i != 3)
            printf(".");
    }
    printf("/%d\n", preffix);
}

void Debug(unsigned int path, int preffix) {
    for (int i = BITS - 1; i >= 0; i--)
        if (path & (1LL << i))
            printf("1");
        else
            printf("0");
    printf("/%d\n", preffix);
}

int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    Trie *root = new Trie();
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        int l = strlen(s + 1);
        bool type = false;
        if (s[1] == '+')
            type = true;
        int p = 2;
        unsigned int path = 0;
        for (int i = 1; i <= BITS / 8; i++) {
            int x = 0;
            while (p <= l && isdigit(s[p])) {
                x = x * 10 + s[p] - '0';
                p++;
            }
            path = (path << 8) + x;
            p++;
        }
        int preffix = 0;
        if (p > l)
            preffix = BITS;
        else
            while (p <= l) {
                preffix = preffix * 10 + s[p] - '0';
                p++;
            }
        Insert(root, path, preffix, type);
        //Debug(path, preffix);
    }
    DFS(root, 0, 0);
    if (bad)
        printf("-1\n");
    else {
        printf("%d\n", answer.size());
        for (auto &it : answer) {
            Convert(it.first, it.second);
            //Debug(it.first, it.second);
        }
    }
    return 0;
}