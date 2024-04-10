#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 111111;

char str[N];
long long k;
int n,
    cnt[N], arr[N], rank[N], tmpArr[N], tmpRank[2][N], height[N];
long long sum[N];
vector <int> pos[N];

int main () {
    cin >> str >> k;
    n = strlen(str);
    if (k > (long long)(1 + n) * n / 2) {
        printf("No such line.\n");
        return 0;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++ i) {
        cnt[(int)str[i]] += 1;
    }
    for (int i = 1; i < 256; ++ i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++ i) {
        rank[i] = cnt[(int)str[i]] - 1;
    }
    if (n == 1) {
        arr[0] = 0;
    } else {
        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; ++ i) {
                tmpRank[0][i] = rank[i] + 1;
                tmpRank[1][i] = i + len < n? rank[i + len] + 1: 0;
            }
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++ i) {
                cnt[tmpRank[1][i]] += 1;
            }
            for (int i = 1; i <= n; ++ i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = 0; i < n; ++ i) {
                tmpArr[-- cnt[tmpRank[1][i]]] = i;
            }
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++ i) {
                cnt[tmpRank[0][i]] += 1;
            }
            for (int i = 1; i <= n; ++ i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i > -1; -- i) {
                arr[-- cnt[tmpRank[0][tmpArr[i]]]] = tmpArr[i];
            }
            rank[arr[0]] = 0;
            for (int i = 1; i < n; ++ i) {
                rank[arr[i]] = rank[arr[i - 1]] + ((tmpRank[0][arr[i]] != tmpRank[0][arr[i - 1]]) || (tmpRank[1][arr[i]] != tmpRank[1][arr[i - 1]]));
            }
        }
    }
    sum[n] = 0;
    for (int i = n - 1; i > -1; -- i) {
        sum[i] = sum[i + 1] + n - arr[i];
    }
    for (int i = 0; i < n; ++ i) {
        pos[i].clear();
    }
    for (int i = 0, tmp = 0; i < n; ++ i) {
        if (rank[i]) {
            int j = arr[rank[i] - 1];
            while (i + tmp < n && j + tmp < n && str[i + tmp] == str[j + tmp]) {
                tmp += 1;
            }
            pos[tmp].push_back(rank[i]);
            if (tmp) {
                tmp -= 1;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        sort(pos[i].begin(), pos[i].end());
    }
    int curLeft = 0,
        curRight = n;
    long long curLcp = 0,
        curRank = k + n;
    while (true) {
        if (curRight - curLeft >= curRank) {
            for (int i = 0; i < curLcp; ++ i) {
                printf("%c", str[arr[curLeft] + i]);
            }
            printf("\n");
            break;
        }
        curRank -= curRight - curLeft;
        for (vector <int> :: iterator iter = pos[curLcp].begin();
                iter != pos[curLcp].end(); ++ iter) {
            if (curLeft < *iter && *iter < curRight) {
                if (sum[curLeft] - sum[*iter] - curLcp * (*iter - curLeft) >= curRank) {
                    curRight = *iter;
                    break;
                }
                curRank -= sum[curLeft] - sum[*iter] - curLcp * (*iter - curLeft);
                curLeft = *iter;
            }
        }
        curLcp += 1;
    }
    return 0;
}