#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans1, ans2, co1[110], co2[110], co3[110], co4[110];
string str1, str2;

int main() {
    scanf("%d", &n);

    cin >> str1 >> str2;

    for(int i = 0; i < n; i++) {
        co1[str1[i] - '0']++;
        co2[str2[i] - '0']++;

        co3[str1[i] - '0']++;
        co4[str2[i] - '0']++;
    }

    for(int i = 9; i > 0; i--) {
        ans1 += min(co4[i], co3[i-1]);
        if (co4[i] > co3[i-1]) co4[i-1] += (co4[i] - co3[i-1]);
    }

    int win = 0,win2 = 0;
    for(int i = 9; i > 0; i--) {
        int tmp = co1[i];
        ans2 += co1[i];
        co1[i] = max(0, co1[i] - win);
        ans2 -= co1[i];

        win = max(0, win - tmp);
        //printf("%d %d %d %d\n", i, co2[i], co1[i], tmp);
        ans2 += min(co2[i], co1[i]);
        if (co2[i] > co1[i]) win += (co2[i] - co1[i]);
        if (co1[i] > co2[i]) win2 += (co1[i] - co2[i]);
       // printf("%d %d %d\n", i, win, win2);
    }

    ans2 += co1[0];
    co1[0] = max(0, co1[0] - win);
    ans2 -= co1[0];
    ans2 += min(co2[0], co1[0]);

    printf("%d\n", n - ans2);
    printf("%d\n", ans1);

    return 0;
}