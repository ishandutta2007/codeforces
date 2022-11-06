#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll t;
char a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll n;
    	cin >> n;
    	ll A = 0;
    	ll B = 0;
    	string s1;
    	string s2;
    	ll gagal = 0;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	for(ll i = 1; i <= n; i++)
    	{
    		char ct;
    		ct = a[i];
    		if(ct == '0')
    		{
    			if(A < B)
    			{
    				s1 += "(";
    				s2 += ")";
    				A++;
    				B--;
    			}
    			else
    			{
    				s1 += ")";
    				s2 += "(";
    				A--;
    				B++;
    			}
    			if(A < 0)gagal = 1;
    			if(B < 0)gagal = 1;
    		}
    		else
    		{
    			if(A == 1 && B == 1 && (i < n && a[i + 1] == '0'))
    			{
    				A++;
    				B++;
    				s1 += "(";
    				s2 += "(";
    			}
    			else
    			if(min(A, B) == 0)
    			{
    				A++;
    				B++;
    				s1 += "(";
    				s2 += "(";
    			}
    			else
    			{
    				A--;
    				B--;
    				s1 += ")";
    				s2 += ")";
    			}
    		}
    		if(gagal)break;
    	}
    	if(A != 0)gagal = 1;
    	if(B != 0)gagal = 1;
    	if(gagal)cout << "NO\n";
    	else
    	{
    		cout << "YES\n";
    		cout << s1 << "\n";
    		cout << s2 << "\n";
    	}
    }
}