#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pi 3.14159265358979323846

using namespace std;

int n, m, k, j, len;
string s;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ld n,r;
    cin >> n >> r;
    ld a=pi/n;
    cout.precision(7);
    cout <<fixed<< r*sinl(a)/(1-sinl(a));
    return 0;
}