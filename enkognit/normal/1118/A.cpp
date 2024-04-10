#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, l, r, x, y, a[100001];
string s;


int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        cout << min(n*a,n/2*b+n%2*a) << "\n";
    }
    return 0;
}