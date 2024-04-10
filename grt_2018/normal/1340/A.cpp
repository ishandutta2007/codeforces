#include <bits/stdc++.h>

using namespace std;

int p[100*1000+10], inv[100*1000+10];
bool done[100*1000+10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> p[i];
            inv[p[i]] = i;
            done[i] = 0;
        }
        int last = 1;
        bool ok = 1;
        while(last <= n) {
            int pos = inv[last];
            while(pos <= n && !done[pos]) {
                if(p[pos] != last) {
                    ok = 0;
                    break;
                }
                done[pos] = 1;
                last++;
                pos++;
            }
            if(!ok) break;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}