//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

int value[1 + MAXN];
pair<int, int> tree[1 + 4 * MAXN];
int where, change;

void Update(int node, int left, int right) {
    if (left == right) {
        if (change == -1)
            tree[node].first = 1;
        else
            tree[node].second = 1;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle);
    else
        Update(2 * node + 1, middle + 1, right);
    if (tree[2 * node].second == tree[2 * node + 1].first)
        tree[node] = make_pair(tree[2 * node].first, tree[2 * node + 1].second);
    if (tree[2 * node].second > tree[2 * node + 1].first)
        tree[node] = make_pair(tree[2 * node].first, tree[2 * node].second - tree[2 * node + 1].first + tree[2 * node + 1].second);
    if (tree[2 * node].second < tree[2 * node + 1].first)
        tree[node] = make_pair(tree[2 * node].first + tree[2 * node + 1].first - tree[2 * node].second, tree[2 * node + 1].second);
}

int Query(int node, int left, int right, int which) {
    if (left == right)
        return value[left];
    int middle = (left + right) / 2;
    int toLeft = max(0, tree[2 * node].second - tree[2 * node + 1].first);
    if (which <= toLeft)
        return Query(2 * node, left, middle, which);
    return Query(2 * node + 1, middle + 1, right, which - toLeft);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int index, type;
        cin >> index >> type;
        where = index;
        if (!type) {
            change = -1;
            Update(1, 1, n);
        }
        else {
            cin >> value[index];
            change = 1;
            Update(1, 1, n);
        }
        if (tree[1].second == 0) {
            cout << "-1\n";
            continue;
        }
        cout << Query(1, 1, n, tree[1].second) << "\n";
    }
    return 0;
}