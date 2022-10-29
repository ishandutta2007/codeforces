#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 3e5 + 2;
int n, m;
long long a[N], b[N], f[N], L[N], R[N];
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    long long min_v = 0;
    for (int i = 1; i <= n ; i  ++)
    {
        cin>>a[i];
        b[i] = a[i] * m + b[i  - 1];
        f[i] = f[i - 1] + a[i];
        min_v = min(min_v, f[i]);
        L[i] = f[i] - min_v;
    }
    min_v = 0;
    long long sum = 0;
    for (int i = n ; i >=1 ; i -- )
    {
        sum += a[i];
        min_v = min(min_v, sum);
        R[i] = sum - min_v;
    }
    long long max_v = b[n];
    for (int i = n ; i >= 0; i --)
    {
        max_v = max(max_v, R[i + 1] + b[i]);
        ans = max(ans, max_v - b[i] + L[i]);
    }
    cout<<ans;
    return 0;
}