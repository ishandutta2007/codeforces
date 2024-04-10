#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

void solve(int k)
{
        bool inv = true;
        string F = "", mid = "";
        for(int i = 0; i < n; i++){
                int x = a[i] / k;
                for(int j = 0; j < x / 2; j++){
                        F += char('a' + i);
                }
                if(x % 2){
                        mid += char('a' + i);
                }
        }
        if(mid.size() > 1){
                inv = false;
        }

        string F1 = F;
        reverse(F1.begin(), F1.end());
        F = F + mid + F1;

        if(k % 2 && !inv){
                return;
        }

        cout << k << "\n";
        for(int i = 0; i < k; i++){
                cout << F;
                reverse(F.begin(), F.end());
        }
        exit(0);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int s = 0, k;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                s += a[i];
                if(i == 0){
                        k = a[i];
                } else{
                        k = __gcd(k, a[i]);
                }
        }
        for(int i = k; i >= 1; i--){
                if(k % i){
                        continue;
                }
                solve(i);
        }
        cout << 0 << "\n";
        for(int i = 0; i < n; i++){
                while(a[i]--){
                        cout << char('a' + i);
                }
        }
}