#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 500300;
const long long mod = 1e15 + 3;

using namespace std;

int n;
int s;
int mx;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s += x;
        mx = max(mx, x);
    }
    cout << n * mx - s << endl;
}