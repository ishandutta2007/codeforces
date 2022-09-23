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
    int cnt = 0;
    while(n){
        if(n % 10 == 7 || n % 10 == 4)
            cnt++;
        n /= 10;
    }
    if(cnt == 4 || cnt == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
}