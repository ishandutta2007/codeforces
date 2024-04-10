#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int MAXD = 18;

struct Trie {
    int numbers;
    Trie *son[2];

    Trie() {
        numbers = 0;
        son[0] = son[1] = NULL;
    }
};

void Update(Trie *node, long long value, int add, int level) {
    if (level == MAXD + 1) {
        node->numbers += add;
        return;
    }
    if (node->son[value % 2] == NULL)
        node->son[value % 2] = new Trie();
    Update(node->son[value % 2], value / 10, add, level + 1);
}

char s[1 + MAXD];
int length;

int Query(Trie *node, int level) {
    if (level == MAXD + 1)
        return node->numbers;
    if (node->son[s[level]] == NULL)
        return 0;
    return Query(node->son[s[level]], level + 1);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    Trie *root = new Trie();
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        char type;
        scanf("%c", &type);
        if (type == '+' || type == '-') {
            long long x;
            scanf("%I64d\n", &x);
            int add = 1;
            if (type == '-')
                add = -1;
            Update(root, x, add, 1);
        }
        else {
            scanf("%s\n", s + 1);
            length = strlen(s + 1);
            for (int j = 1; j <= length; j++)
                s[j] -= '0';
            for (int j = length + 1; j <= MAXD; j++)
                s[j] = 0;
            for (int j = 1; j <= length / 2; j++)
                swap(s[j], s[length - j + 1]);
            printf("%d\n", Query(root, 1));
        }
    }
    return 0;
}