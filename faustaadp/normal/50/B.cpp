#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
string s;
ll d[999], has;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> s;
    ll L = s.length();
    for(ll i = 0; i < L; i++)
    {
        d[s[i]] += 1;
        has += d[s[i]];
        d[s[i]] += 1;
    }
    cout << has << "\n";
}