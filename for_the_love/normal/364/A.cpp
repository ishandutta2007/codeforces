#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 4005;
int sum[N], S[N * 10];
int main(){
    long long a;
    string s = "";
    cin >> a;
    cin >> s;
    int n = s.size();

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i - 1] - '0');

    if (!a){
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            S[sum[j] - sum[i - 1]]++;
        for (int i = 1; i <= 40000; i++)
            ans += (long long)S[0] * S[i];
        ans *= 2;
        ans += (long long)S[0] * S[0];

        cout << ans << endl;
    }else{
        for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            S[sum[j] - sum[i - 1]]++;
        long long ans = 0;
        for (int i = 1; i <= 40000; i++)
        if (a % i == 0 && a / i <= 40000) ans += (long long)S[i] * S[a / i];
        cout << ans << endl;
    }
}