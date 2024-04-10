#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2222;

using namespace std;

int n;
int a[N];
vector<int> res;

void make(int p)
{
        if(p < 1){
                return;
        }
        res.push_back(p);
        for(int i = 1; i <= p / 2; i++){
                swap(a[i], a[p - i + 1]);
        }
}

int get(int x)
{
        for(int i = 1; i <= n; i++){
                if(a[i] == x){
                        return i;
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                if(a[i] % 2 != i % 2){
                        cout << -1 << "\n";
                        return;
                }
        }
        res.clear();
        for(int i = n; i > 1; i -= 2){
                int y = get(i);
                make(y);
                int x = get(i - 1);
                make(x - 1);
                make(x + 1);
                make(3);
                make(i);
        }
        for(int i = 1; i <= n; i++){
                assert(a[i] == i);
        }
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
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