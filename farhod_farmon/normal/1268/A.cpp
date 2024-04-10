#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = c - '0';
                if(i <= k){
                        b[i] = a[i];
                } else{
                        b[i] = b[i - k];
                }
        }

        bool good = true;
        for(int i = 1; i <= n; i++){
                if(a[i] > b[i]){
                        good = false;
                        break;
                } else if(a[i] < b[i]){
                        break;
                }
        }

        if(good){
                cout << n << "\n";
                for(int i = 1; i <= n; i++){
                        cout << b[i];
                }
        } else{
                cout << n << "\n";
                int g = k;
                b[g] += 1;
                while(b[g] == 10){
                        b[g] = 0;
                        g -= 1;
                        b[g] += 1;
                }
                for(int i = 1; i <= n; i++){
                        if(i > k){
                                b[i] = b[i - k];
                        }
                        cout << b[i];
                }
        }
}