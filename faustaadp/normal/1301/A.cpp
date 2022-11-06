#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e6 + 5;
ll t;
string A, B, C;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    cin >> t;
    while(t--)
    {
        cin >> A;
        cin >> B;
        cin >> C;
        ll n = A.length();
        ll bisa = 1;
        for(ll i = 0; i < n; i++)
            if((A[i] != C[i]) && (B[i] != C[i]))
            {
                bisa = 0;
                break;
            }
        if(bisa)
            cout << "YES\n";
        else
            cout << "NO\n";
    }     
}