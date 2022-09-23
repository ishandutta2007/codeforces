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

lli a, b, c;

int main()
{
    cin >> a >> b >> c;
    if(c == 0){
        if(a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else if(c < 0){
        if((b - a) % c == 0 && b <= a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else{
        if((b - a) % c == 0 && b >= a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}