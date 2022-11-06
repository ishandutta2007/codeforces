#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e3 + 5;
ll t, n, A[999];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll K = sqrt(n);
        ll udah = 0;
        for(ll i = 2; i <= K; i++)
        {
            if(n % i == 0)
            {
                n /= i;
                udah++;
                A[udah] = i;
                if(udah == 2)
                {
                    A[3] = n;
                    break; 
                }
            }
        }
        if(udah == 2 && A[2] < A[3])
            cout << "YES\n" << A[1] << " " << A[2] << " " << A[3] << "\n";
        else
            cout << "NO\n";
    }
}