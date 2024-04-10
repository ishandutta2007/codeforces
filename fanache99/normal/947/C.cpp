#include <fstream>

using namespace std;

const int MAXLOG = 29;
const int MAXN = 300000;

struct Node {
    int weight;
    Node *son[2];

    Node() {
        son[0] = son[1] = NULL;
        weight = 0;
    }
};

Node *root;
int v[1 + MAXN];

void Update(int x, int add) {
    Node *node = root;
    root->weight += add;
    for (int i = MAXLOG; i >= 0; i--) {
        int which = 0;
        if (x & (1 << i))
            which = 1;
        if (!node->son[which])
            node->son[which] = new Node();
        node = node->son[which];
        node->weight += add;
    }
}

int Query(int x) {
    Node *node = root;
    int answer = 0;
    for (int i = MAXLOG; i >= 0; i--) {
        int which = 0;
        if (x & (1 << i))
            which = 1;
        if (node->son[which] && node->son[which]->weight) {
            if (which)
                answer += 1 << i;
            node = node->son[which];
        }
        else {
            if (1 - which)
                answer += 1 << i;
            node = node->son[1 - which];
        }
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    root = new Node();
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        Update(x, 1);
    }
    for (int i = 1; i <= n; i++) {
        int x = Query(v[i]);
        printf("%d ", v[i] ^ x);
        Update(x, -1);
    }
    return 0;
}