#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]]++;
        }

        int best = 0;
        for(int i = 1; i < N; i++){
                if(c[i] > c[best]){
                        best = i;
                }
        }
        cout << n - c[best] << "\n";
        for(int i = 2; i <= n; i++){
                if(a[i] == best || a[i - 1] != best){
                        continue;
                }
                if(a[i - 1] < a[i]){
                        cout << 2 << " " << i << " " << i - 1 << "\n";
                } else{
                        cout << 1 << " " << i << " " << i - 1 << "\n";
                }
                a[i] = best;
        }
        for(int i = n - 1; i >= 1; i--){
                if(a[i] == best || a[i + 1] != best){
                        continue;
                }
                if(a[i] < a[i + 1]){
                        cout << 1 << " " << i << " " << i + 1 << "\n";
                } else{
                        cout << 2 << " " << i << " " << i + 1 << "\n";
                }
                a[i] = best;
        }
}