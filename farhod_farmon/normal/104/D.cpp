#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

long long n, k, p;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> k >> p;
    bool b = false;
    if(n % 2 && k > 0){
        b = true;
        k--;
        n--;
    }
    for(int i = 1; i <= p; i++){
        long long x;
        cin >> x;
        if(b && x - 1 == n){
            cout << 'X';
            continue;
        }
        if((n - x) / 2 + 1 + (n / 2) * (x % 2) <= k)
            cout << 'X';
        else
            cout << '.';
    }
}