#include <bits/stdc++.h>

using namespace std;

set<int> possib[10000];

int solve(int x, int mask, int c, int m) {
    vector<int> num, v;
    for(int tmp = x, id = 0; id < 4; id++, tmp /= 10)
        num.push_back(tmp % 10);
    reverse(num.begin(), num.end());

    v.push_back(num[0]);
    for(int b = 0; b < 3; b++) {
        if(mask & (1 << b)) v.back() = v.back() * 10 + num[b+1];
        else v.push_back(num[b+1]);
    }

    for(int i = 0; i < 3 && v.size() > 1; i++) {
        int ci = c % 3, mi = min(m % 3, (int)v.size() - 2);
        if(ci == 0) v[mi] += v[mi + 1];
        if(ci == 1) v[mi] -= v[mi + 1];
        if(ci == 2) v[mi] *= v[mi + 1];
        v.erase(v.begin() + mi + 1);
        c /= 3; m /= 3;
    }
    return v[0];
}


int k, m, ans, can[20010];

int main() {
    scanf("%d %d", &k, &m);

    for(int i = 1; i <= 9999; i++) {
        memset(can, 0, sizeof can);
        for(int mask = 0; mask < 8; mask++)
            for(int c = 0; c < 27; c++)
                for(int mm = 0; mm < 6; mm++)
                    can[solve(i, mask, c, mm) + 10000] = 1;

        for(int x = 0; x < 20010; x++) {
            if(can[x] % 2 && (k-x+10000 <= 9999 && k-x+10000 >= -9999) && can[abs(k-x+10000)] < 2) {
                printf("%04d%04d\n", i, abs(k-x+10000));
                can[abs(k-x+10000)] += 2;
                ans++;
            }
            else if(can[x] % 2 && (k+x-10000 <= 9999 && k+x-10000 >= -9999) && can[abs(k+x-10000)] < 2) {
                printf("%04d%04d\n", i, abs(k+x-10000));
                can[abs(k+x-10000)] += 2;
                ans++;
            }
            if(ans == m) return 0;
        }
    }
    assert(ans == m);
    return 0;
}