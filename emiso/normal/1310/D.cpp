#include <bits/stdc++.h>

using namespace std;

int n, m, d[88][88], ans = INT_MAX;
pair<int, int> gd[88][88][88];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &d[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < 88; k++)
                gd[i][j][k] = {100000001, -1};
            for(int k = 1; k <= n; k++)
                gd[i][j][k-1] = {d[i][k] + d[k][j], k};
            sort(gd[i][j], gd[i][j] + 88);
        }

    if(m == 2) {
        int idx = 0;
        while(gd[1][1][idx].second == 1) idx++;
        ans = gd[1][1][idx].first;
    } else if(m == 4) {
        for(int j = 1; j <= n; j++) {
            int tmp = 0;

            int idx = 0;
            while(gd[1][j][idx].second == 1 || gd[1][j][idx].second == j) idx++;
            tmp += gd[1][j][idx].first;

            idx = 0;
            while(gd[j][1][idx].second == 1 || gd[j][1][idx].second == j) idx++;
            tmp += gd[j][1][idx].first;

            ans = min(ans, tmp);
        }
    } else if(m == 6) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                int tmp = 0;

                int idx = 0;
                while(gd[1][j][idx].second == 1 || gd[1][j][idx].second == j || gd[1][j][idx].second == k) idx++;
                tmp += gd[1][j][idx].first;

                idx = 0;
                while(gd[j][k][idx].second == 1 || gd[j][k][idx].second == j || gd[j][k][idx].second == k) idx++;
                tmp += gd[j][k][idx].first;

                idx = 0;
                while(gd[k][1][idx].second == 1 || gd[k][1][idx].second == j || gd[k][1][idx].second == k) idx++;
                tmp += gd[k][1][idx].first;

                ans = min(ans, tmp);
            }
        }
    } else if(m == 8) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    int tmp = 0;

                    int idx = 0;
                    while(gd[1][j][idx].second == 1 || gd[1][j][idx].second == j || gd[1][j][idx].second == k || gd[1][j][idx].second == l) idx++;
                    tmp += gd[1][j][idx].first;

                    idx = 0;
                    while(gd[j][k][idx].second == 1 || gd[j][k][idx].second == j || gd[j][k][idx].second == k || gd[j][k][idx].second == l) idx++;
                    tmp += gd[j][k][idx].first;

                    idx = 0;
                    while(gd[k][l][idx].second == 1 || gd[k][l][idx].second == j || gd[k][l][idx].second == k || gd[k][l][idx].second == l) idx++;
                    tmp += gd[k][l][idx].first;

                    idx = 0;
                    while(gd[l][1][idx].second == 1 || gd[l][1][idx].second == j || gd[l][1][idx].second == k || gd[l][1][idx].second == l) idx++;
                    tmp += gd[l][1][idx].first;

                    ans = min(ans, tmp);
                }
            }
        }
    } else {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    for(int i = 1; i <= n; i++) {
                        int tmp = 0;

                        int idx = 0;
                        while(gd[1][j][idx].second == 1 || gd[1][j][idx].second == j || gd[1][j][idx].second == k || gd[1][j][idx].second == l || gd[1][j][idx].second == i) idx++;
                        tmp += gd[1][j][idx].first;

                        idx = 0;
                        while(gd[j][k][idx].second == 1 || gd[j][k][idx].second == j || gd[j][k][idx].second == k || gd[j][k][idx].second == l || gd[j][k][idx].second == i) idx++;
                        tmp += gd[j][k][idx].first;

                        idx = 0;
                        while(gd[k][l][idx].second == 1 || gd[k][l][idx].second == j || gd[k][l][idx].second == k || gd[k][l][idx].second == l || gd[k][l][idx].second == i) idx++;
                        tmp += gd[k][l][idx].first;

                        idx = 0;
                        while(gd[l][i][idx].second == 1 || gd[l][i][idx].second == j || gd[l][i][idx].second == k || gd[l][i][idx].second == l || gd[l][i][idx].second == i) idx++;
                        tmp += gd[l][i][idx].first;

                        idx = 0;
                        while(gd[i][1][idx].second == 1 || gd[i][1][idx].second == j || gd[i][1][idx].second == k || gd[i][1][idx].second == l || gd[i][1][idx].second == i) idx++;
                        tmp += gd[i][1][idx].first;

                        ans = min(ans, tmp);
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}