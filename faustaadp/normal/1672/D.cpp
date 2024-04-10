#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
ll a[NN], b[NN], vis[NN], utg[NN];
vector<ll> v[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        stack<ll> st;
        for(ll i = n; i >= 1; i--)
            st.push(a[i]);
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        for(ll i = 1; i <= n; i++)
            utg[i] = 0;
        ll now = 1;
        ll gagal = 0;
        for(ll i = 1; i <= n; i++)
        {
            while(!st.empty() && st.top() != b[i])
            {
                utg[st.top()]++;
                st.pop();
            }
            if(st.empty())
            {
                gagal = 1;
                break;
            }
            if(utg[st.top()])
                utg[st.top()]--;
            else
                st.pop();
        }
        if(gagal)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}