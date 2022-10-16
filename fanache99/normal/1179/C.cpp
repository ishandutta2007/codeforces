#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

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

const int MAXN = 300000;
const int MAXM = 300000;
const int INF = 1000000000;

int a[1 + MAXN];
int b[1 + MAXM];
pair<int, int> vn[1 + MAXN + MAXM];

class Node {
    public:
        int value;
        int priority;
        int type;
        Node *left, *right;
        int sum, biggest;

        void Update() {
            sum = left->sum + right->sum - type;
            biggest = max(left->biggest - type + right->sum, max(-type + right->sum, right->biggest));
        }

        Node() {
            value = type = sum = 0;
            priority = biggest = -INF;
            left = right = nullptr;
        }

        Node(int _value, int _priority, int _type, Node *_left, Node *_right) {
            value = _value;
            priority = _priority;
            type = _type;
            left = _left;
            right = _right;
            Update();
        }
};

int MyRand() {
    return (rand() << 16) | rand();
}

Node *root, *nil;

pair<Node*, Node*> Split(Node *node, int value, int type) {
    if (node == nil)
        return make_pair(nil, nil);
    if (make_pair(value, type) < make_pair(node->value, node->type)) {
        pair<Node*, Node*> temp = Split(node->left, value, type);
        node->left = temp.second;
        node->Update();
        return make_pair(temp.first, node);
    }
    else {
        pair<Node*, Node*> temp = Split(node->right, value, type);
        node->right = temp.first;
        node->Update();
        return make_pair(node, temp.second);
    }
}

Node *Insert(Node *node, int value, int type, int priority) {
    if (node == nil)
        return new Node(value, priority, type, nil, nil);
    if (priority > node->priority) {
        pair<Node*, Node*> temp = Split(node, value, type);
        return new Node(value, priority, type, temp.first, temp.second);
    }
    if (make_pair(value, type) < make_pair(node->value, node->type))
        node->left = Insert(node->left, value, type, priority);
    else
        node->right = Insert(node->right, value, type, priority);
    node->Update();
    return node;
}

Node *Join(Node *left, Node *right) {
    if (left == nil)
        return right;
    if (right == nil)
        return left;
    if (left->priority > right->priority) {
        left->right = Join(left->right, right);
        left->Update();
        return left;
    }
    else {
        right->left = Join(left, right->left);
        right->Update();
        return right;
    }
}

Node *Erase(Node *node, int value, int type) {
    if (make_pair(value, type) == make_pair(node->value, node->type))
        return Join(node->left, node->right);
    if (make_pair(value, type) < make_pair(node->value, node->type))
        node->left = Erase(node->left, value, type);
    else
        node->right = Erase(node->right, value, type);
    node->Update();
    return node;
}

int Query(Node *node, int limit) {
    if (node == nil || node->biggest <= limit)
        return -1;
    if (node->right->biggest > limit)
        return Query(node->right, limit);
    if (-node->type + node->right->sum > limit)
        return node->value;
    return Query(node->left, limit - node->right->sum + node->type);
}

void Initialize(int n, int m) {
    nil = new Node();
    root = nil;
    for (int i = 1; i <= n; i++)
        vn[i] = make_pair(a[i], -i);
    for (int i = 1; i <= m; i++)
        vn[n + i] = make_pair(b[i], i);
    sort(vn + 1, vn + n + m + 1);
    for (int i = 1; i <= n + m; i++)
        if (vn[i].second > 0)
            root = Insert(root, vn[i].first, 1, MyRand());
        else
            root = Insert(root, vn[i].first, -1, MyRand());
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    srand(time(0));
    int n = Read(), m = Read();
    for (int i = 1; i <= n; i++)
        a[i] = Read();
    for (int i = 1; i <= m; i++)
        b[i] = Read();
    Initialize(n, m);
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int type = Read(), x = Read(), y = Read();
        if (type == 1) {
            root = Erase(root, a[x], -1);
            root = Insert(root, y, -1, MyRand());
            a[x] = y;
        }
        else {
            root = Erase(root, b[x], 1);
            root = Insert(root, y, 1, MyRand());
            b[x] = y;
        }
        printf("%d\n", Query(root, 0));
    }
    return 0;
}