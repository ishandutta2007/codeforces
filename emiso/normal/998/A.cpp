#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > pack;
int n, x;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        pack.emplace_back(x, i);
    }
    sort(pack.begin(), pack.end());

    if(n == 1 || (n == 2 && pack[0].first == pack[1].first)) {
        printf("-1\n");
    } else {
        printf("1\n%d\n", pack[0].second + 1);
    }

    return 0;
}