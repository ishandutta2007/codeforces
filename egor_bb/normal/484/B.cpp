#pragma comment (linker, "/STACK:10000000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
  
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort
 
using namespace std;
 

int n, a[1000005], b[1000005], mx = 0, ans;

int main()
{
    cin >> n;
        for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        mx = max(t, mx);
        a[t] = 1;
    }
    for (int i = 1; i < 1000005; i++){
        if (a[i]) b[i + 1] = i;
        else b[i + 1] = b[i];
    }
    for (int i = 0; i < 1000005; i++){
        if (a[i]){
            for (int j = 2 * i; j <= 2 * mx; j += i){
                if ( j > mx ) ans = max(ans, mx % i);
                                else ans = max(ans, b[j] % i);
            }
        }
    }
    cout << ans << '\n';
}