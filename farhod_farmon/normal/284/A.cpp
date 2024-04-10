#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 10100;

using namespace std;

int p;

bool f(int x)
{
    int y = 1;
    for(int i = 1; i <= p - 1; i++){
        y = (y * x) % p;
        int nx = (y - 1 + p) % p;
        if(nx == 0 && i != p - 1)
            return false;
        if(nx != 0 && i == p - 1)
            return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> p;
    int cnt = 0;
    for(int i = 1; i < p; i++)
        cnt += f(i);
    cout << cnt << endl;
}