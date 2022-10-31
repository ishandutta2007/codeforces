#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
ll nums[100100], pref[100100], suf[100100], plast[100100], slast[100100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &nums[i]);

    ll last = nums[0], used = 0;
    plast[0] = last;
    for (int i = 1; i < n; i++) {
        ll diff = nums[i] - last;
        if (diff > 0) plast[i] = nums[i];
        else {
            plast[i] = nums[i] + abs(diff) + 1;
            used += abs(diff) + 1;
        }
        pref[i] = used;
        last = plast[i];
    }

    last = nums[n-1], used = 0;
    slast[n-1] = last;
    for (int i = n-2; i >= 0; i--) {
        ll diff = nums[i] - last;
        if (diff > 0) slast[i] = nums[i];
        else {
            slast[i] = nums[i] + abs(diff) + 1;
            used += abs(diff) + 1;
        }
        suf[i] = used;
        last = slast[i];
    }

    ll ans = min(pref[n-1], suf[0]);
    for (int i = 0; i < n-1; i++) {
        ans = min(ans, pref[i] + suf[i+1] + (plast[i] == slast[i+1]));
    }
    printf("%lld\n", ans);

    return 0;
}