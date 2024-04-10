#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

vector < pair < int, pair < int, int > > > v;
int n, a[N];

bool can(int x)
{
    v.clear();
    int j = x + 1;
    for(int i = 1, h = n - x + 1; i <= x; i++, h++){
        while(a[j] <= a[i] && j < n - x)
            j++;
        if(a[h] <= a[j] || a[j] <= a[i] || j > n - x)
            return false;
        v.pb({a[h], {a[j], a[i]}});
        j++;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0,
        r = n / 3;
    while(l < r){
        int m = (l + r) / 2;
        if(can(m + 1))
            l = m + 1;
        else
            r = m;
    }
    can(l);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i].fi << " " << v[i].se.fi << " " << v[i].se.se << endl;
}