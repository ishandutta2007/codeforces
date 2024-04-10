#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e4 + 5;
ll n, t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll K = sqrt(n);
        ll hz = n - 1;
        for(ll i = 2; i <= K; i++)
        {
            if(n % i == 0)
            {
                ll A = n / i;
                ll B = i;
                ll C = A * (B - 1);
                // cout << C << "\n";
                hz = min(hz, C);
            }
        }
        cout << hz << " " << n - hz << "\n";
    }
}