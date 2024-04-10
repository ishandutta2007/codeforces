#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 10000001;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int l;
int r;
int a[N];
int b[N];
pair < int, int > p[N];

void solve()
{
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(p + 1, p + n + 1);
    int last = -1e9;
    for(int i = 1; i <= n; i++){
        int j = p[i].se;
        b[j] = max(last + a[j] + 1, l);
        if(b[j] > r){
            cout << -1 << endl;
            return;
        }
        last = b[j] - a[j];
    }
    for(int i = 1; i <= n; i++)
        cout << b[i] << " ";
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}