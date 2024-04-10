#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int INF = 1e9 + 13;
const int N = 5000 + 13;

/*
3 4 2 2
1 2 3 59

*/

int a[N];
li dp[N][N];

int main() {
    int n, k, x;
    cin >> n >>k >> x;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        dp[0][i] = a[i];
    }

    for(int i = 1; i <= x; i++) {
        deque<li> deq;
        deq.push_back(-1);
        for(int j = 0; j <= n; j++) {
            if(j - k >= 0 && deq.front() == dp[i - 1][j - k])
                deq.pop_front();

            while(!deq.empty() && deq.back() < dp[i - 1][j])
                deq.pop_back();
            deq.push_back(dp[i - 1][j]);

            if(deq.front() != -1)
                dp[i][j + 1] = deq.front() + a[j + 1];
        }
    }

//    for(int i = 0; i <= x; i++) {
//        for(int j = 0; j <= n; j++) {
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//        }
//    }

    cout << dp[x][n] << endl;
}