#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>
#include <queue>


using namespace std;


int n, k;
int c[100001];
int id[100001];
bool used[100001];


int main() {
    cin >> n >> k; 
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }  
    long long ans = 0;
    long long sum1 = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &id[i]);
        id[i]--;
        used[id[i]] = 1;
        sum1 += c[id[i]];
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (!used[(i + 1) % n]) {
                ans += c[i] * c[(i + 1) % n];
            }
        }
    }
    long long ans1 = 0;
    for (int i = 0; i < k; i++) {
        ans += 1LL * c[id[i]] * sum;
        ans -= 1LL * c[id[i]] * c[id[i]];
        ans1 += 1LL * c[id[i]] * (sum1 - c[id[i]]);
    }
    ans1 /= 2LL;
    ans -= ans1;
    cout << ans << endl;
    return 0;
}