#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int a[N];
int c[N];
int tl[N], tr[N];
vector < int > g[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                g[i].clear();
                c[i] = 0;
        }
        vector < int > v = {0};
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]] += 1;
                while(!v.empty() && a[i] <= a[v.back()]){
                        v.pop_back();
                }
                tl[i] = v.back();
                v.push_back(i);
        }
        v.clear();
        v.push_back(n + 1);
        a[n + 1] = 0;
        for(int i = n; i >= 1; i--){
                while(!v.empty() && a[i] <= a[v.back()]){
                        v.pop_back();
                }
                tr[i] = v.back();
                v.push_back(i);
        }
        set < int > s;
        for(int i = 1; i <= n; i++){
                if(c[i]){
                        s.insert(i);
                }
                int k = tr[i] - tl[i] - 1;
                g[k].push_back(a[i]);
        }
        for(int i = 1; i <= n; i++){
                while(!s.empty() && *(--s.end()) > n - i + 1){
                        s.erase(--s.end());
                }
                if(s.size() == n - i + 1){
                        cout << 1;
                } else{
                        cout << 0;
                }
                for(int x: g[i]){
                        c[x] -= 1;
                        if(!c[x]){
                                s.erase(x);
                        }
                }
        }
        cout << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}