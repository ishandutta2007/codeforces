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
    for(long long i = 2; i <= n + 1; i++){
        if(i == 2)
            cout << 2 << "\n";
        else
            cout << i * i * (i - 1) - i + 2 << "\n";
    }
}