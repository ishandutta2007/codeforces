#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;


long long a[2][2];
long long cnt[2];
long long cnts[1000101];


int main() {
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) {
        cout << "1" << endl;
        return 0;
    }
    if (a[0][0] == 0 && a[0][1] == 1 && a[1][0] == 0 && a[1][1] == 0) {
        cout << "01" << endl;
        return 0;
    }
    if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 1 && a[1][1] == 0) {
        cout << "10" << endl;
        return 0;
    }
    if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] != 0) {
        while (1LL * cnt[1] * (cnt[1] - 1) < 1LL * a[1][1] * 2) {
            cnt[1]++;
        }
        if (1LL * cnt[1] * (cnt[1] - 1) != 1LL * a[1][1] * 2) {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int i = 0; i < cnt[1]; i++) {
            printf("1");
        }
        printf("\n");
        return 0;
    }
    if (a[0][0] != 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) {
        while (1LL * cnt[0] * (cnt[0] - 1) < 1LL * a[0][0] * 2) {
            cnt[0]++;
        }
        if (1LL * cnt[0] * (cnt[0] - 1) != 1LL * a[0][0] * 2) {
            cout << "Impossible" << endl;
            return 0;
        }
        for (int i = 0; i < cnt[0]; i++) {
            printf("0");
        }
        printf("\n");
        return 0;
    }
    if (a[0][0] == 0 && a[0][1] != 0 && a[1][0] == 0 && a[1][1] != 0) {
        while (1LL * cnt[1] * (cnt[1] - 1) < 1LL * a[1][1] * 2) {
            cnt[1]++;
        }
        if (a[0][1] == cnt[1]) {
            cout << "0";
            for (int i = 0; i < cnt[1]; i++) {
                printf("1");
            }
            printf("\n");
            return 0;
        }
    }
     if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] != 0 && a[1][1] != 0) {
        while (1LL * cnt[1] * (cnt[1] - 1) < 1LL * a[1][1] * 2) {
            cnt[1]++;
        }
        if (a[1][0] == cnt[1]) {
            for (int i = 0; i < cnt[1]; i++) {
                printf("1");
            }
            cout << "0";
            printf("\n");
            return 0;
        }
    }
    if (a[0][0] != 0 && a[0][1] == 0 && a[1][0] != 0 && a[1][1] == 0) {
        while (1LL * cnt[0] * (cnt[0] - 1) < 1LL * a[0][0] * 2) {
            cnt[0]++;
        }
        if (a[1][0] == cnt[0]) {
            cout << "1";
            for (int i = 0; i < cnt[0]; i++) {
                printf("0");
            }
            printf("\n");
            return 0;
        }
    }
    if (a[0][0] != 0 && a[0][1] != 0 && a[1][0] == 0 && a[1][1] == 0) {
        while (1LL * cnt[0] * (cnt[0] - 1) < 1LL * a[0][0] * 2) {
            cnt[0]++;
        }
        if (a[0][1] == cnt[0]) {
            for (int i = 0; i < cnt[0]; i++) {
                printf("0");
            }
            cout << "1";
            printf("\n");
            return 0;
        }
    }
    cnt[0] = 1;
    cnt[1] = 1;
    while (1LL * cnt[0] * (cnt[0] - 1) < 1LL * a[0][0] * 2) {
        cnt[0]++;
    }
    if (1LL * cnt[0] * (cnt[0] - 1) != 1LL * a[0][0] * 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    while (1LL * cnt[1] * (cnt[1] - 1) < 1LL * a[1][1] * 2) {
        cnt[1]++;
    }
    if (1LL * cnt[1] * (cnt[1] - 1) != 1LL * a[1][1] * 2) {
        cout << "Impossible" << endl;
        return 0;
    }
   // cout << cnt[0] << ' ' << cnt[1] << endl;
    if (1LL * cnt[0] * cnt[1] != 1LL * a[0][1] + a[1][0]) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (a[0][1] == 0) {
        for (long long i = 0; i < cnt[1]; i++) {
            printf("1");
        }
        for (long long i = 0; i < cnt[0]; i++) {
            printf("0");
        }
        printf("\n");
        return 0;
    }
    if (a[1][0] == 0) {
        for (long long i = 0; i < cnt[0]; i++) {
            printf("0");
        }
        for (long long i = 0; i < cnt[1]; i++) {
            printf("1");
        }
        printf("\n");
        return 0;
    }
    long long l = 0;
    long long sum0 = 0;
    while (a[0][1] != 0) {
        while (cnt[1] - l > a[0][1]) {
            l++;
        }
        cnts[l]++;
        sum0++;
        a[0][1] -= cnt[1] - l;
    }
    cnts[cnt[1]] = cnt[0] - sum0;
    for (long long i = 0; i <= cnt[1]; i++) {
        for (long long j = 0; j < cnts[i]; j++) {
            printf("0");
        }
        if (i != cnt[1]) {
            printf("1");
        }
    }
    printf("\n");
    return 0;
}