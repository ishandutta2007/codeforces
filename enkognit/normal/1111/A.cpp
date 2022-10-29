#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, j, k, l, r, kol, ans, a[400001];
string s,d,f="aeiou";

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    cin >> d;
    if (s.size()!=d.size()) {cout << "No";exit(0);}
    for (int i = 0; i < s.size(); i++)
    {
        ll o,p;
        o=(f.find(s[i])!=string::npos);
        p=(f.find(d[i])!=string::npos);
        if (o!=p) {cout << "No";exit(0);}
    }
    cout << "Yes";
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/