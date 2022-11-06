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
        ll bisa;
        ll n, k;
        cin >> n >> k;
        if((k * k) > n)
            bisa = 0;
        else
        if((k % 2) == (n % 2))
            bisa = 1;
        else
            bisa = 0;
        if(bisa)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}