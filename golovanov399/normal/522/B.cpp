#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
    vector<long long> ans(n);
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    for (int i = 0; i < n; i++)
        ans[i] = s - a[i];
    int mx = -1, mmx = -1;
    int cur = -1;
    for (int i = 0; i < n; i++){
        if (b[i] > mx){
            cur = i;
            mmx = mx;
            mx = b[i];
        } else if (b[i] > mmx)
            mmx = b[i];
    }
    for (int i = 0; i < n; i++){
        if (i == cur)
            ans[i] *= mmx;
        else
            ans[i] *= mx;
    }
    for (auto x : ans){
        printf("%I64d ", x);
    }
    puts("");

    return 0;
}