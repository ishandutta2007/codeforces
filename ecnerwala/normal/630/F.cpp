#include<bits/stdc++.h>
using namespace std;

long long choose[1000][1000];

int main() {
for(int i = 0; i < 1000; i++) choose[i][0] = choose[i][i] = 1;
for(int i = 0; i < 1000; i++) for(int j = 1; j < i; j++) choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
int n; cin >> n;
cout << choose[n][5] + choose[n][6] + choose[n][7] << '\n';
}