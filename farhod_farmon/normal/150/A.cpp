#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

long long n;
vector < long long > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            n /= i;
            v.pb(i);
        }
    }
    if(n > 1)
        v.pb(n);
    if(v.size() == 1 || (n == 1 && v.empty())){
        cout << 1 << "\n" << 0 << "\n";
        return 0;
    }
    if(v.size() == 2){
        cout << 2 << "\n";
        return 0;
    }
    cout << 1 << "\n" << v[0] * v[1] << "\n";
    return 0;
}