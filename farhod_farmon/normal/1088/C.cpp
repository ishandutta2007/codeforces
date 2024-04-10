#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        int s = 0;
        cout << n + 1 << "\n";
        for(int i = n - 1; i >= 0; i--){
                int x = (a[i] + s) % n;
                int g = (i - x + n) % n;
                cout << 1 << " " << i + 1 << " " << g << "\n";
                s = (s + g) % n;
        }
        cout << 2 << " " << n << " " << n << "\n";
}