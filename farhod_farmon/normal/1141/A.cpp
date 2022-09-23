#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        int a = 0, b = 0;
        while(n % 2 == 0){
                n /= 2;
                a--;
        }
        while(n % 3 == 0){
                n /= 3;
                b--;
        }
        while(m % 2 == 0){
                m /= 2;
                a++;
        }
        while(m % 3 == 0){
                m /= 3;
                b++;
        }
        if(a < 0 || b < 0 || n != m){
                cout << -1 << "\n";
        } else {
                cout << a + b << "\n";
        }
}