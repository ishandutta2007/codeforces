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

long long n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = n / 7; i >= 0; i--){
        int x = (n - i * 7) / 4;
        if(i * 7 + x * 4 == n){
            for(int j = 0; j < x; j++)
                cout << 4;
            for(int j = 0; j < i; j++)
                cout << 7;
            return 0;
        }
    }
    cout << -1;
}