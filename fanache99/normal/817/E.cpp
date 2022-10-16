#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXLOG = 26;

struct Trie {
    int sum;
    Trie *son[2];

    Trie() {
        sum = 0;
        son[0] = son[1] = NULL;
    }
};

void Update(Trie *root, int value, int add) {
    Trie *node = root;
    root->sum += add;
    for (int bit = MAXLOG; bit >= 0; bit--) {
        int which = 0;
        if (value & (1 << bit))
            which = 1;
        if (!node->son[which])
            node->son[which] = new Trie();
        node = node->son[which];
        node->sum += add;
    }
}

int Query(Trie *root, int value, int limit) {
    int answer = 0;
    Trie *node = root;
    for (int bit = MAXLOG; bit >= 0; bit--) {
        int which = 0;
        if (value & (1 << bit))
            which = 1;
        if ((limit & (1 << bit))) {
            if (node->son[which])
                answer += node->son[which]->sum;
            which = 1 - which;
        }
        if (!node->son[which])
            node->son[which] = new Trie();
        node = node->son[which];
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int q = Read();
    Trie *root = new Trie();
    for (int i = 1; i <= q; i++) {
        int type = Read();
        if (type == 1) {
            int x = Read();
            Update(root, x, 1);
        }
        if (type == 2) {
            int x = Read();
            Update(root, x, -1);
        }
        if (type == 3) {
            int x = Read(), y = Read();
            printf("%d\n", Query(root, x, y));
        }
    }
    return 0;
}