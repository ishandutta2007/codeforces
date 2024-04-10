#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int k2, k3, k5, k6;
long long ans;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("three.in");
    //fout("three.out");
    ios_base::sync_with_stdio(0);
    cin >> k2 >> k3 >> k5 >> k6;
    while(k2 && k5 && k6){
        k2--;
        k5--;
        k6--;
        ans += 256;
    }
    while(k2 && k3){
        k2--;
        k3--;
        ans += 32;
    }
    cout << ans << endl;
}