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

using namespace std;

lli mod = 1e9 + 7;

vector < vector < lli > > mult(vector < vector < lli > > x, vector < vector < lli > > y)
{
    vector < vector < lli > > v;
    v.resize(2);
    for(lli i = 0; i < 2; i++){
        v[i].resize(2);
        for(lli j = 0; j < 2; j++)
            v[i][j] = (x[i][0] * y[0][j] + x[i][1] * y[1][j]) % mod;
    }
    return v;
}

vector < vector < lli > > pw(vector < vector < lli > > x, lli n)
{
    if(n == 1)
        return x;
    if(n % 2)
        return mult(x, pw(x, n - 1));
    return pw(mult(x, x), n / 2);
}

vector < vector < lli > > a, b;
lli A, B, n, x;

int main()
{
    //fin
    //fout
    cin >> A >> B >> n >> x;
    a.resize(2);
    b.resize(2);
    for(int i = 0; i < 2; i++){
        a[i].resize(2);
        b[i].resize(2);
        a[i][0] = a[i][1] = 0;
        b[i][0] = b[i][1] = 0;
    }
    a[0][0] = x;
    a[0][1] = 1;
    b[0][0] = A;
    b[1][0] = B;
    b[1][1] = 1;
    a = mult(a, pw(b, n));
    cout << a[0][0] << endl;
}