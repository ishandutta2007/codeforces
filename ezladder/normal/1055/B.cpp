#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
ll k;
ll a[100007];
int ans = 0;

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> n >> tt >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= k;
    }

    for (int i = 1; i < n; i++){
        if (a[i] <= 0 && a[i - 1] > 0) ans++;
    }
    if (a[n - 1] > 0) ans++;

    while(tt--){
        int type;
        cin >> type;
        if (type == 0){
            cout << ans << "\n";
        } else {
            int v, val;
            cin >> v >> val;
            v--;
            a[v] += val;
            if (a[v] > 0 && a[v] - val <= 0){
                ans++;
                if (v + 1 < n){
                    if (a[v + 1] > 0) ans--;
                }
                if (v - 1 >= 0){
                    if (a[v - 1] > 0) ans--;
                }
            }
        }
    }
}