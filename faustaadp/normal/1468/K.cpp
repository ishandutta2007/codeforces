#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
ll dx[NN], dy[NN];
string s;
ll cek(ll gX, ll gY)
{
	ll X = 0, Y = 0;
	for(ll i = 0; i < n; i++)
	{
		ll nx = X + dx[s[i]];
		ll ny = Y + dy[s[i]];
		if(nx == gX && ny == gY)
			continue;
		X = nx;
		Y = ny;
	}
	// cout << gX << " " << gY << " " << X << " " << Y << "\n";
	return(X == 0 && Y == 0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> s;
    	n = s.length();
    	dx['L'] = -1;
    	dx['R'] = 1; 
    	dy['D'] = -1;
    	dy['U'] = 1;
    	ll X = 0, Y = 0;
    	ll jX = 0, jY = 0;
    	for(ll i = 0; i < n; i++)
    	{
    		X += dx[s[i]];
    		Y += dy[s[i]];
    		if(X == 0 && Y == 0)
    			continue;
    		// cout << X << " " << Y << "\n";
    		if(cek(X, Y))
    		{
    			jX = X;
    			jY = Y;
    			break;
    		}
    	}
    	// cout << "\n";
    	cout << jX << " " << jY << "\n";
    }
}