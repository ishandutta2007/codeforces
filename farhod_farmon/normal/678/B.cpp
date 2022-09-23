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

lli d[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
lli ne = 0, ru = 0;

bool f(lli x)
{
    return x % 400 == 0 || x % 4 == 0 && x % 100 != 0;
}

int main()
{
    lli n;
    cin >> n;
    lli x = n;
    while(true){
        if(f(x))
            d[1] = 29;
        else
            d[1] = 28;
        for(int i = 0; i < 12; i++)
            ne = (ne + d[i]) % 7;
        x++;
        if(f(x) == f(n) && ne == 0){
            cout << x << endl;
            return 0;
        }
    }
}