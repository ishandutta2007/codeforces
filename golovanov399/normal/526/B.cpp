#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[5000][2];

int main(){

    int n;
    cin >> n;
    int m = (1 << (n + 1)) - 1;
    long long ans = 0;
    vector<int> qw(m + 1);
    for (int i = 2; i < m + 1; i++){
        cin >> a[i / 2][i % 2];
    }
    for (int i = m / 2; i >= 1; i--){
        ans += abs(a[i][0] + qw[i + i] - a[i][1] - qw[i + i + 1]);
        qw[i] = max(a[i][0] + qw[i + i], a[i][1] + qw[i + i + 1]);
    }
    cout << ans << "\n";

    return 0;
}