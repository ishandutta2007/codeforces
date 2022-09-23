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
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
bool used[N];

void solve()
{
    cin >> n;
    int m = n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        used[x] = true;
        while(used[m]){
            cout << m << " ";
            m--;
        }
        cout << endl;
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