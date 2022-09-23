#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

int f(long long x, long long g)
{
    int cnt = 0;
    while(x % g == 0){
        x /= g;
        cnt++;
    }
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int cnt = 0;
    int g12 = f(a1, 2) + f(b1, 2);
    int g13 = f(a1, 3) + f(b1, 3);
    int g22 = f(a2, 2) + f(b2, 2);
    int g23 = f(a2, 3) + f(b2, 3);
    while(g13 > g23){
        g13--;
        g12++;
        cnt++;
        if(a1 % 3 == 0)
            a1 = a1 - a1 / 3;
        else
            b1 = b1 - b1 / 3;
    }
    while(g13 < g23){
        g23--;
        g22++;
        cnt++;
        if(a2 % 3 == 0)
            a2 = a2 - a2 / 3;
        else
            b2 = b2 - b2 / 3;
    }
    while(g12 > g22){
        cnt++;
        g12--;
        if(a1 % 2 == 0)
            a1 /= 2;
        else
            b1 /= 2;
    }
    while(g12 < g22){
        cnt++;
        g22--;
        if(a2 % 2 == 0)
            a2 /= 2;
        else
            b2 /= 2;
    }
    if(1ll * a1 * b1 != 1ll * a2 * b2)
        cout << -1 << endl;
    else{
        cout << cnt << endl;
        cout << a1 << " " << b1 << endl;
        cout << a2 << " " << b2 << endl;
    }
}