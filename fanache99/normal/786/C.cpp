//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXLOG = 42;

int nodes = 1, v[1 + MAXN], root[1 + MAXN + 1], distinct[1 + MAXN + 1];
int sum[1 + MAXLOG * MAXN], leftSon[1 + MAXLOG * MAXN], rightSon[1 + MAXLOG * MAXN];

void BuildTree(int node, int left, int right) {
    if (left == right)
        return;
    int middle = (left + right) / 2;
    nodes++;
    leftSon[node] = nodes;
    nodes++;
    rightSon[node] = nodes;
    BuildTree(leftSon[node], left, middle);
    BuildTree(rightSon[node], middle + 1, right);
}

int where, add;
int last[1 + MAXN];

int Update(int node, int left, int right) {
    nodes++;
    int newNode = nodes;
    if (left == right) {
        sum[newNode] = sum[node] + add;
        return newNode;
    }
    int middle = (left + right) / 2;
    leftSon[newNode] = leftSon[node];
    rightSon[newNode] = rightSon[node];
    if (where <= middle)
        leftSon[newNode] = Update(leftSon[node], left, middle);
    else
        rightSon[newNode] = Update(rightSon[node], middle + 1, right);
    sum[newNode] = sum[leftSon[newNode]] + sum[rightSon[newNode]];
    return newNode;
}

int Query(int node, int left, int right, int limit) {
    if (left == right)
        return left;
    int middle = (left + right) / 2;
    if (sum[leftSon[node]] < limit)
        return Query(rightSon[node], middle + 1, right, limit - sum[leftSon[node]]);
    return Query(leftSon[node], left, middle, limit);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    BuildTree(1, 1, n);
    root[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
        where = i;
        add = 1;
        root[i] = Update(root[i + 1], 1, n);
        distinct[i] = distinct[i + 1];
        if (last[v[i]]) {
            where = last[v[i]];
            add = -1;
            root[i] = Update(root[i], 1, n);
        }
        else
            distinct[i]++;
        last[v[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int answer = 0, j = 1;
        while (j <= n) {
            answer++;
            if (distinct[j] <= i)
                break;
            j = Query(root[j], 1, n, i + 1);
        }
        cout << answer << " ";
    }
    return 0;
}