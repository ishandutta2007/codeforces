#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

long double a, x, y;
int cnt = 1;

void f(long double xx, long double yy)
{
    if(xx < x && x < xx + a && yy < y && y < yy + a){
        cout << cnt << endl;
        exit(0);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> x >> y;
    long double cury = 0.0;
    int i = 1;
    while(cury <= 1e6){
        if(i % 2 == 0 || i == 1){
            f(a / (-2.0), cury);
            cnt += 1;
        }
        else{
            f(-a, cury);
            cnt += 1;
            f(0, cury);
            cnt += 1;
        }
        cury += a;
        i += 1;
    }
    cout << -1 << endl;
}