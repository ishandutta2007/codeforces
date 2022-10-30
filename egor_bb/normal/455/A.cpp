#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>


#define maxn 100005
#define ll long long 

using namespace std;

int main(){
ll a[maxn], n, num[maxn], dp[maxn];
for (int i = 0; i < maxn; i++){
a[i]=0; num[i]=0; dp[i]=0;
}
cin >> n;
for (int i = 0; i < n; i++){
cin >> a[i];
num[a[i]]++;
}
dp[1] = num[1];
for (int i = 2; i < maxn; i++){
dp[i] = max(dp[i - 1], dp[i - 2] + 1ll*num[i]*i);
}
cout << dp[maxn - 1];
}