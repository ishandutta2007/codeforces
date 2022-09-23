#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int d[N];

void solve()
{
        cin >> n;
        multiset < int > s, t;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x] = i;
                s.insert(i);
                t.insert(1);
                d[i] = 1;
        }
        for(int i = 1; i <= n; i++){
                int j = a[i];
                if(d[j] != *(--t.end())){
                        cout << "No" << "\n";
                        return;
                }
                t.erase(t.find(d[j]));
                auto p = s.lower_bound(j);
                p++;
                if(p != s.end()){
                        t.erase(t.find(d[*p]));
                        d[*p] += d[j];
                        t.insert(d[*p]);
                }
                s.erase(j);
        }
        cout << "Yes" << "\n";
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}