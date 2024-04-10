#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, m;
int t;
int k;
char c[4] = {'U', 'D', 'L', 'R'};
int main() {
    //scanf("%d", &t);
    t = 1;
    while (t --) {
        scanf("%d %d %d", &n, &m, &k);
        vector<pair<int, int> > d;
        if (0) {

        }else {
            for (int i = 1; i < n && k; i++) {
                int stp = min(k, m - 1);
                k -= stp;
                if (stp)
                    d.push_back(make_pair(stp, 3));
                stp = min(k ,m - 1);
                k -= stp;
                if (stp)
                    d.push_back(make_pair(stp, 2));
                if (k)
                    d.push_back(make_pair(1, 1)), k --;
            }
            int stp = min(k, m - 1);
            k -= stp;
            if (stp)
                d.push_back(make_pair(stp, 3));
            for (int i = 1; i < m && k; i ++) {
                int stp = min(k, n - 1);
                k -= stp;
                if (stp)
                    d.push_back(make_pair(stp, 0));
                stp = min(k ,n - 1);
                k -= stp;
                if (stp)
                    d.push_back(make_pair(stp, 1));
                if (k)
                    d.push_back(make_pair(1, 2)), k --;
            }
            stp = min(k, n - 1);
            k -= stp;
            if (stp)
                d.push_back(make_pair(stp, 0));
        }
        if (k) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%d\n", d.size());
        for (auto u:d)
            printf("%d %c\n", u.first, c[u.second]);
    }
    return 0;
}