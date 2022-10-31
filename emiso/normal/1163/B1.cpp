#include <bits/stdc++.h>

#define MN 100010

using namespace std;

int n, x, ans, f[MN];
map<int, int> ff;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        if(f[x]) {
            ff[f[x]]--;
            if(ff[f[x]] == 0) ff.erase(f[x]);
        }
        f[x]++;
        ff[f[x]]++;

        if(ff.size() == 1) {
            if((*ff.begin()).first  == 1) ans = i;
            if((*ff.begin()).second == 1) ans = i;
        } else if(ff.size() == 2) {
            if((*ff.begin()) == pair<const int, int>(1, 1)) ans = i;
            else if((*ff.rbegin()) == pair<const int, int>((*ff.begin()).first + 1, 1)) ans = i;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}