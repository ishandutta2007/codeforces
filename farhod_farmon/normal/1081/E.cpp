#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long MX = 400400;

using namespace std;

int n;
long long a[N];

long long good(long long x)
{
        long long y = sqrt(x);
        while(y * y > x)y--;
        while(y * y < x)y++;
        if(y * y == x){
                return y;
        }
        return -1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i += 2){
                cin >> a[i];
        }
        long long last = 0;
        for(int i = 1; i <= n; i += 2){
                long long pre = last;
                last++;
                while(last <= MX && good(last * last + a[i + 1]) == -1){
                        last++;
                }
                if(last == MX + 1){
                        cout << "No" << "\n";
                        return 0;
                }
                a[i] = last * last - pre * pre;
                last = good(last * last + a[i + 1]);
        }
        cout << "Yes" << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
}