#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

char s[1100000];
int st[1100000];
int fim = 0;

int n, m;

set< pair<int, int> > br;

int tree[1100000];

int read(int x) {
    int s = 0;
    while (x > 0) {
        s += tree[x];
        x -= x&-x;
    }
    return s;
}

void update(int x, int delta) {
    while (x <= n+10) {
        tree[x] += delta;
        x += x&-x;
    }
}

pair<int, pair<int, int> > queries[110000];
int ans[110000];

int main() {
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') st[fim++] = i;
        else if (fim != 0) {
            br.insert(make_pair(st[--fim]+1, i+1));
            update(i+1, 1);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &queries[i].first, &queries[i].second.first);
        queries[i].second.second = i;
    }

    sort(queries, queries+m);
    int st = 1;

    for (int i = 0; i < m; i++) {
        while (!br.empty() && queries[i].first > br.begin()->first ) {
            update(br.begin()->second, -1);
            br.erase(br.begin());
        }

        ans[queries[i].second.second] = read(queries[i].second.first);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]*2);
    }
}