#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<pair<int, int>, pair<int, int> > table;

int answer = 0, first = 0, second = 0;

void Try(int index, int a, int b, int c) {
    if (table.find(make_pair(a, b)) == table.end()) {
        if (answer < min(min(a, b), c)) {
            answer = min(min(a, b), c);
            first = index;
            second = 0;
        }
        return;
    }
    pair<int, int> which = table[make_pair(a, b)];
    int value = min(min(a, b), c + which.second);
    if (answer < value) {
        answer = value;
        first = which.first;
        second = index;
    }
}

void Add(int index, int a, int b, int c) {
    if (table.find(make_pair(a, b)) == table.end()) {
        table[make_pair(a, b)] = make_pair(index, c);
        return;
    }
    pair<int, int> value = table[make_pair(a, b)];
    if (value.second < c) {
        value.first = index;
        value.second = c;
        table[make_pair(a, b)] = value;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int x = min(a, min(b, c));
        int y = max(a, max(b, c));
        b = a + b + c - x - y;
        a = x;
        c = y;
        Try(i, a, b, c);
        Try(i, b, c, a);
        Try(i, a, c, b);
        Add(i, a, b, c);
        Add(i, b, c, a);
        Add(i, a, c, b);
    }
    if (second == 0)
        printf("1\n%d\n", first);
    else
        printf("2\n%d %d\n", first, second);
    return 0;
}