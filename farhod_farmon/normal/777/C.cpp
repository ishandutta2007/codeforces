#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const ll N = 100100;
const ll MX = 1e16;
const ll MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int R[N];
vector < vector < int > > a;

void solve()
{
    cin >> n >> m;
    a.resize(n + 2);
    for(int i = 0; i <= n + 1; i++)
        a[i].resize(m + 2);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        int L = 1;
        for(int i = 1; i <= n; i++){
            if(a[i][j] < a[i - 1][j]){
                R[L] = max(R[L], i - 1);
                L = i;
            }
        }
        R[L] = max(R[L], n);
    }
    for(int i = 2; i <= n; i++)
        R[i] = max(R[i], R[i - 1]);
    int k, l, r;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> l >> r;
        if(R[l] >= r)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}