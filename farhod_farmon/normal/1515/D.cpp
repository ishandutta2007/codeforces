#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

void solve()
{
        int n, l, r;
        cin >> n >> l >> r;
        vector < int > c(n, 0);
        for(int i = 0; i < l; i++){
                int x;
                cin >> x;
                c[x - 1] += 1;
        }
        for(int i = 0; i < r; i++){
                int x;
                cin >> x;
                c[x - 1] -= 1;
        }
        vector < int > A[2], B[2];
        for(int x: c){
                if(x > 0){
                        A[x % 2].push_back(x);
                } else if(x < 0){
                        B[(-x) % 2].push_back(-x);
                }
        }
        int res = 0;
        while(!A[1].empty() && !B[1].empty()){
                int x = A[1].back();
                int y = B[1].back();
                A[1].pop_back();
                B[1].pop_back();
                res += 1;
                A[0].push_back(x - 1);
                B[0].push_back(y - 1);
        }

        if(!B[1].empty()){
                swap(A, B);
        }
        for(int x: B[0]){
                res += x / 2;
        }
        for(int x: A[0]){
                res += x / 2;
        }

        if(!A[1].empty()){
                int s = 0;
                for(int x: B[0]){
                        s += x;
                }
                int g = A[1].size() - A[1].size() % 2;
                g = min(g, s);
                res += g / 2 + (A[1].size() - g);
                for(int x: A[1]){
                        res += x / 2;
                }
        }

        cout << res << "\n";
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