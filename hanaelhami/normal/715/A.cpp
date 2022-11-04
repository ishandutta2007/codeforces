#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define F first
#define S second
using namespace std;

const int MAXN = 1001 * 1001 ;


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n ;
    cout << 2 << '\n';
    for(int i = 1 ; i < n ; i ++ )
    {
        int z = (i+2)*(i+1)*(i+1)*(i+2) ;
        cout << ((i+2)*(i+1)*(i+2)-i)  << '\n';
        //x = (i+2)*(i+1);
    }
}