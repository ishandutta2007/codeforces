#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int q;
deque < int > a;
pair < int, int > res[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a.push_back(x);
        }
        for(int i = 1; i <= n; i++){
                int A = a.front();
                a.pop_front();
                int B = a.front();
                a.pop_front();
                a.push_back(min(A, B));
                a.push_front(max(A, B));
                res[i] = {A, B};
        }
        for(int i = 1; i <= q; i++){
                long long x;
                cin >> x;
                if(x <= n){
                        cout << res[x].fi << " " << res[x].se << "\n";
                } else{
                        x -= n;
                        if(x % (n - 1) == 0){
                                x = n - 1;
                        } else{
                                x %= n - 1;
                        }
                        cout << a[0] << " " << a[x] << "\n";
                }
        }
}