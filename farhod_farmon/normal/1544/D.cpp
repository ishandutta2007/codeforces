#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int a[N];
int b[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                b[i] = 0;
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                b[a[i]] += 1;
                res += (b[a[i]] == 1);
        }
        set < int > s;
        for(int i = 1; i <= n; i++){
                if(!b[i]){
                        s.insert(i);
                }
        }
        cout << res << "\n";
        for(int i = 1, j = 1; i <= n; i++){
                if(b[a[i]] > 1){
                        for(int x : {*s.begin(), *(--s.end())}) {
                                if(x != i){
                                        b[a[i]]--;
                                        a[i] = x;
                                        s.erase(x);
                                        break;
                                }
                        }
                }
                cout << a[i] << " ";
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}