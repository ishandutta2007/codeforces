#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll long long

const int N = 100100;
const long long mod = 1e15 + 3;

using namespace std;

ll n, k;
vector < ll > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.pb(i);
            if(i * i != n)
                v.pb(n / i);
        }
    }
    sort(v.begin(), v.end());
    if(k > v.size())
        cout << -1 << endl;
    else
        cout << v[k - 1] << endl;
}