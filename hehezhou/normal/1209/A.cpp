#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[110], n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int flag = 1;
        for(int j = 1; j <= n; j++) {
            if(a[i] == a[j]) {
                if(j < i) flag = 0;
            }
            else if(a[i] % a[j] == 0) flag = 0;
        }
        ans += flag;
    }
    return cout << ans << '\n', 0;
}