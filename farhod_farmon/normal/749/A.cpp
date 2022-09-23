#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 17;
const int MX = 10010;

using namespace std;

int n;
vector < int > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    if(n % 2){
        n -= 3;
        v.pb(3);
    }
    while(n){
        n -= 2;
        v.pb(2);
    }
    cout << v.size() << endl;
    for(auto x: v)
        cout << x << " ";
}