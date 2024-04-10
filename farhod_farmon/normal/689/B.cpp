#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 200200;

using namespace std;

int n, p[N], d[N];
bool used[N];
vector < int > v;

void f(int x, int y = -1)
{
    if(x < 1 || x > n || used[x])
        return;
    if(y != -1)
        d[x] = d[y] + 1;
    used[x] = true;
    v.pb(x);
}

int main()
{
    //freopen( "angry.in", "r", stdin );
    //freopen( "angry.out", "w", stdout );
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    f(1);
    for(int i = 0; i < v.size(); i++){
        int x = v[i];
        f(p[x], x);
        f(x - 1, x);
        f(x + 1, x);
    }
    for(int i = 1; i <= n; i++)
        cout << d[i] << " ";
}