#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 30300;
const int mod = 998244353;

using namespace std;


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
                int n;
                cin >> n;
                vector<int> a(n);
                vector<int> b(n);
                vector<pair<int, int>> A(n);
                vector<pair<int, int>> B(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        A[i] = {a[i], i};
                }
                for(int i = 0; i < n; i++){
                        cin >> b[i];
                        B[i] = {b[i], i};
                }

                sort(A.begin(), A.end());
                sort(B.begin(), B.end());
                int i = n - 1, j = n - 1;
                int ma = a[B.back().se];
                int mb = b[A.back().se];
                while(true){
                        if(i > 0 && A[i - 1].fi >= ma){
                                i -= 1;
                                mb = min(mb, b[A[i].se]);
                        } else if(j > 0 && B[j - 1].fi >= mb){
                                j -= 1;
                                ma = min(ma, a[B[j].se]);
                        } else{
                                break;
                        }
                }
                vector<int> res(n, 0);
                while(i < n){
                        res[A[i++].se] = 1;
                }
                while(j < n){
                        res[B[j++].se] = 1;
                }
                for(int x : res){
                        cout << x;
                }
                cout << "\n";
        }
}