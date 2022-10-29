#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int first[5000][5000], last[5000][5000];
int first_[5000], last_[5000];
int s[10000];
int n, t;
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
        {
            first_[i] = last_[i] = 0;
            for (int j = 0; j < n; j ++)
                first[i][j] = last[i][j] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &s[i]);
            s[i] --;
            for (int j = 0; j < n; j ++)
                if (first_[j] && !first[j][s[i]])
                    first[j][s[i]] = i;
            if (!first_[s[i]])
                first_[s[i]] = i;
        }

        for (int i = n; i >= 1; i --) {
            for (int j = 0; j < n; j ++)
                if (last_[j] && !last[s[i]][j])
                    last[s[i]][j] = i;
            if (!last_[s[i]])
                last_[s[i]] = i;
        }
        bool ans = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                ans |= (first[i][j] && last[j][i] && first[i][j] < last[j][i])||(first[i][j] && last_[i] && first[i][j] < last_[i]);
        ans?puts("YES"):puts("NO");
    }
    return 0;

}