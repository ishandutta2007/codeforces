#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define debug(x) cout<<(#x)<<" is "<<(x)<<endl
#define lb(arr,n,x) lower_bound(arr,arr+n,x)-arr
#define ub(arr,n,x) upper_bound(arr,arr+n,x)-arr
#define endl "\n"
#define PI 3.14159265358979323846  /* pi */
#define sqr(x) (x)*(x)
#define all(v)  ((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
 
typedef long long ll;
typedef long double ld;
//Calculation of (x^y)%mm
ll mod_exp(ll x,ll y,ll mm)
{
    if(y==0)
        return(1);
    else if(y%2==0)
        return(mod_exp((x*x)%mm,y/2,mm));
    else
        return((x*mod_exp((x*x)%mm,(y-1)/2,mm))%mm);
}
bool is_lowercase(char x)
{
	int gd='x';
	if(gd>96)
		return true;
	return false;
}
 
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
 
string s;
cin>>s;
std::vector<char> v;
char arr[]={'a','e','i','o','u','y'};
rep(i,6)
	v.pb(arr[i]);
 
rep(i,s.length())
{
	if(isupper(s[i]))
		s[i]=tolower(s[i]);
}
rep(i,s.size())
{
	
	if(find(all(v),s[i])!=v.end())
	{
		continue;
	}
	else
		cout<<"."<<s[i];
}
 
return 0;
}