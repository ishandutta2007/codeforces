#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;
const int mod = 998244353;

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
                string s;
                cin >> n >> s;
                string A(n, '.'), B(n, '.');
                vector < int > v;
                int l = n, r = -1;
                for(int i = 0; i < n; i++){
                        if(s[i] == '0'){
                                v.push_back(i);
                        } else{
                                if(l == n){
                                        l = i;
                                }
                                r = i;
                        }
                }
                if(!v.empty()){
                        if(v.size() % 2 || l > v[0] || r < v.back()){
                                cout << "NO\n";
                                continue;
                        }
                }
                for(int i = 0; i < v.size(); i++){
                        if(i % 2 == 0){
                                A[v[i]] = '(';
                                B[v[i]] = ')';
                        } else{
                                B[v[i]] = '(';
                                A[v[i]] = ')';
                        }
                }
                A[l] = B[l] = '(';
                A[r] = B[r] = ')';
                int rem = (n - v.size() - 2) / 2;
                for(int i = 0; i < n; i++){
                        if(A[i] == '.'){
                                if(rem > 0){
                                        rem -= 1;
                                        A[i] = B[i] = '(';
                                } else{
                                        A[i] = B[i] = ')';
                                }
                        }
                }
                cout << "YES\n";
                cout << A << "\n";
                cout << B << "\n";
        }
}