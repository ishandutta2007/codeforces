#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e7 + 5;

long long n, i, j, k, x, s[MAXN + 5], l, r, mid, ans;
bool v[MAXN + 5];

bool check(long long x){
    long long i, j;
    for (i = 2; i <= MAXN; i++)
    if (s[i]){
        long long sum = 0;
        for (j = i; j <= x; j *= i){
            sum += x / j;
            if (sum >= s[i]) break;
        }
        if (sum < s[i]) return 0;
    }
    return 1;
}
int main(){
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> x;
        if (x > 1){
            s[2]++;
            s[x + 1]--;
        }
        r += x;
    }
    for (i = 1; i <= MAXN; i++) s[i] += s[i - 1];
    for (i = 2; i <= MAXN; i++)
    if (!v[i]){
        long long sum = 0;
        for (j = i; j <= MAXN; j *= i)
        for (k = j; k <= MAXN; k += j){
            v[k] = 1;
            sum += s[k];
        }
        s[i] = sum;
    }else s[i] = 0;
    l = 1;
    while (l <= r){
        mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}