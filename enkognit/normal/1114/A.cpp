#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, r, a, b ,c ,x ,y ,z;
string s, d;
vector <ll> v;

int main()
{
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (a+b+c<x+y+z) {cout << "NO\n";exit(0);}
    if (x>a) {cout << "NO\n";exit(0);}
    a-=x;
    //cout << a << " ";
    if (b+a<y) {cout << "NO\n";exit(0);}
    ll p=min(a,y);
    a-=p;
    y-=p;
    p=min(b,y);
    b-=p;
    y-=p;
    if (a+b+c<z) {cout << "NO\n";exit(0);}
    cout << "YES\n";
    return 0;
}