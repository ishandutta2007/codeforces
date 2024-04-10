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

ll n, m, k, j;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        ll l, r, d;
        cin >> l >> r >> d;
        if (l>d || r<d) cout << d << "\n"; else
        cout << (r/d+1)*d << "\n";
    }
    return 0;
}