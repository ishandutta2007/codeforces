#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

int a, b;

int f(int &x)
{
    int cnt = 0;
    while(x % 2 == 0){
        x /= 2;
        cnt++;
    }
    while(x % 5 == 0){
        x /= 5;
        cnt++;
    }
    while(x % 3 == 0){
        x /= 3;
        cnt++;
    }
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    int cnt = f(a) + f(b);
    if(a != 1 || b != 1)
        cout << -1 << endl;
    else
        cout << cnt << endl;
}