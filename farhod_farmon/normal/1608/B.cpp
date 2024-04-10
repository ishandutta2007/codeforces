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
                int n, A, b;
                cin >> n >> A >> b;
                swap(A, b);
                vector<int> a(n);
                for(int i = 0; i < n; i++){
                        a[i] = i;
                }
                int x = 0, y = 0;
                if(A >= b){
                        for(int i = 0; i + 1 < n; i += 2){
                                if(x < A){
                                        x += 1;
                                        y += (i > 0);
                                        swap(a[i], a[i + 1]);
                                }
                        }
                } else{
                        for(int i = n - 1; i > 0; i -= 2){
                                if(y < b){
                                        y += 1;
                                        x += (i < n - 1);
                                        swap(a[i], a[i - 1]);
                                }
                        }
                }
                if(y < b){
                        swap(a[n - 1], a[n - 2]);
                }
                if(x < A){
                        swap(a[0], a[1]);
                }
                for(int i = 1; i + 1 < n; i++){
                        b -= (a[i] > a[i - 1] && a[i] > a[i + 1]);
                        A -= (a[i] < a[i - 1] && a[i] < a[i + 1]);
                }
                if(A || b){
                        cout << -1 << "\n";
                        continue;
                }
                for(int x : a){
                        cout << x + 1 << " ";
                }
                cout << "\n";
        }
}