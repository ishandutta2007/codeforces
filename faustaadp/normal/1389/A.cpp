#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        ll ta, tb;
        cin >> ta >> tb;
        if(ta * 2 > tb)
            cout << -1 << " " << -1 << "\n";
        else
            cout << ta << " " << ta * 2 << "\n";
    }
}