#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, a[110], ways[110][10010], waysnew[110][10010], f[110], ans;
set<int> dif;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        f[a[i]]++;
        dif.insert(a[i]);
    }

    ways[0][0] = 1;
    for(int i = 1; i <= 100; i++)
        for(int val = 10000; val >= i; val--)
            for(int many = 1; many <= f[i]; many++) {
                if(val - i * many < 0) break;
                for(int q = 0; q + many <= 100; q++) {
                    ways[q+many][val] = min(2, ways[q+many][val] + ways[q][val - i*many]);
                }
            }

    for(int x = 1; x <= 100; x++) {
        for(int many = 1; many <= f[x]; many++) {
            //printf("%d %d -> %d\n", x, many, ways[many][many * x]);
            if(ways[many][many * x] != 1) continue;
            int tmp = many;

            if(many < f[x] && dif.size() == 1) tmp = n;
            else if(many == f[x] && dif.size() == 2) tmp = n;
            ans = max(ans, tmp);
        }
    }

    printf("%d\n", ans);
    return 0;
}