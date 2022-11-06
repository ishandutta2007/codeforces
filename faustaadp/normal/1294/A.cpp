#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e3 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll A, B, C, n;
        cin >> A >> B >> C >> n;
        ll D = max(A, max(B, C));
        ll E = (D - A) + (D - B) + (D - C);
        if((E <= n) && ((E % 3) == (n % 3)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}