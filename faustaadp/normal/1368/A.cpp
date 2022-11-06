#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        if(a > b)
            swap(a, b);
        ll has = 0;
        while(1)
        {
            has++;
            a += b;
            swap(a, b);
            if(b > n)
                break;
        }
        cout << has << "\n";
    }
}