#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600;
char s[maxn];
int a[maxn];
int debug = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k >> s;
        for(int i = 0; i < n; i += 1) a[i] = s[i] - 'a';
        for(int i = 0, p = 0; i < n; i += 1){
            if(debug){
                cout << i << " " << p << " "; 
                for(int i = 0; i < n; i += 1) cout << char(a[i] + 'a');
                cout << "\n";
            }
            if(p){
                int fm = a[i];
                int sm = i + 1 < n ? a[i + 1] : k;
                int tm = i + 2 < n ? a[i + 2] : k;
                if(fm <= sm and fm <= tm){
                    p = 0;
                    continue;
                }
                if(sm <= tm){
                    swap(a[i], a[i + 1]);
                    continue;
                }
                a[i] = tm;
                a[i + 2] = sm;
                a[i + 1] = fm;
                i += 1;
                continue;
            }
            else{
                int fm = min({a[i], (a[i] + k - 1) % k, (a[i] + 1) % k});
                int sm = i + 1 < n ? min({a[i + 1], (a[i + 1] + k - 1) % k, (a[i + 1] + 1) % k}) : k;
                int tm = i + 2 < n ? a[i + 2] : k;
                if(fm <= sm and fm <= tm){
                    a[i] = fm;
                    continue;
                }
                if(sm <= tm){
                    if(a[i + 1] == sm){
                        a[i] = sm;
                        a[i + 1] = fm;
                        p = 1;
                        continue;
                    }
                    a[i + 1] = a[i];
                    a[i] = sm;
                    p = 1;
                    continue;
                }
                a[i] = tm;
                a[i + 2] = a[i + 1];
                a[i + 1] = fm;
                p = 1;
                i += 1;
            }
        }
        for(int i = 0; i < n; i += 1) cout << char(a[i] + 'a');
        cout << "\n";
    }
    return 0;
}