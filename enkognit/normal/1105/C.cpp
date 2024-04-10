#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, tt, l, r, dp[200001][3], a[3];
vector <ll> v;
string s,d;
map<char,ll> c;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n >> l >> r;
	if (r-l==2) a[0]=1,a[1]=1,a[2]=1; else
    if (r-l==1) a[l%3]++,a[r%3]++; else
    if (l==r) a[l%3]++; else
	{
        a[0]=r/3-(l-1)/3;
     	a[1]=a[0]+(l%3==1)-(r%3==0);
	    a[2]=a[0]+(l%3<=2 && l%3>0)-(r%3<2);
	}
	/*for (int i = 0; i < 3; i++) cout << a[i] << " ";
	cout << "\n";*/
	dp[0][0]=1;
	for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            for (int u = 0; u < 3; u++)
            {
                dp[i+1][(j+u)%3]+=dp[i][j]*a[u];
                dp[i+1][(j+u)%3]%=(ll)(1e9+7);
            }
    cout << dp[n][0];
    return 0;
}