#include<bits/stdc++.h>

using namespace std;
double dp[4000];
int main() {
int n,t;
double p;
cin >> n >> p >> t;
dp[n]=1;
for(; t; t--) {
for(int i = 0; i < n; i++) {
dp[i] += p * dp[i +1];
dp[i +1] *= 1-p;
}
}
double r = n;
for(int i = 0; i <= n; i++) {
r -= dp[i] * i;
}
cout << fixed << setprecision(10)<< r << '\n';
}