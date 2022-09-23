#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

vector < int > v;
long long n, s, k, g;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        long long d = s - (n - i) * x * g;
        if(d < k){
            v.pb(i);
            continue;
        }
        s += x * g;
        g++;
    }
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}