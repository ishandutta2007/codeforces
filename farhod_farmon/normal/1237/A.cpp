#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int s = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s += a[i] / 2;
                b[i] = a[i] / 2;
        }
        for(int i = 1; i <= n; i++){
                if(s > 0 && a[i] < 0 && a[i] % 2){
                        b[i] -= 1;
                        s -= 1;
                } else if(s < 0 && a[i] > 0 && a[i] % 2){
                        b[i] += 1;
                        s += 1;
                }
                cout << b[i] << "\n";
        }
        assert(s == 0);
}