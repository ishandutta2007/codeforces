#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 55;
const int MX = 10000001;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int l;
int a[N];
int b[N];

void solve()
{
    cin >> n >> l;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    if(n == 1){
        cout << "YES" << endl;
        return;
    }
    int la = a[n],
        lb = b[n];
    for(int i = n; i >= 2; i--){
        a[i] -= a[i - 1];
        b[i] -= b[i - 1];
    }
    a[1] += l - la;
    b[1] += l - lb;
    for(int i = 1; i <= n; i++){
        bool bb = true;
        for(int j = 1; j <= n; j++)
            if(a[j] != b[j])
                bb = false;
        if(bb){
            cout << "YES" << endl;
            return;
        }
        for(int j = 1; j < n; j++)
            swap(a[j], a[j + 1]);
    }
    cout << "NO" << endl;
    return;
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