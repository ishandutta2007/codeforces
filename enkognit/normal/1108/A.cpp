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

ll n, m, k, j, o, a[500001];
string s,d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        ll l , r , x, y;
        cin >> l >> r >> x >> y;
        cout << l << " ";
        if (l!=x) cout << x << "\n"; else cout << y << "\n";
    }
    return 0;
}