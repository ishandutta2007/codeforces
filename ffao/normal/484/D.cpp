#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

int n;
int arr[1100000];
long long dp[1100000][2];

long long getMaximumSociability(int a, int b) {
    dp[a][0] = dp[a][1] = 0;
    
    bool esp = false;
    for (int i = a+1; i < b; i++) {
        if ( i+1<b && (arr[i]>arr[i-1]) == (arr[i]>arr[i+1]) ) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][0] + (esp?0:abs(arr[i]-arr[i-1])) );
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + abs(arr[i+1]-arr[i]) );
            esp = true;
        }
        else {
            dp[i][0] = max(dp[i-1][1], dp[i-1][0] + (esp?0:abs(arr[i]-arr[i-1]) ) );
            dp[i][1] = dp[i][0];
            esp = false;
        }
    }

    return max(dp[b-1][0], dp[b-1][1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    long long ans = 0;
    int la = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            ans += getMaximumSociability(la, i);
            la = i;
        } 
    }

    ans += getMaximumSociability(la, n);
    cout << ans << endl;
}