#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
string f;
string a[N];
string b[N];
map < string, int > used;

void solve()
{
    cin >> n >> f;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        for(int j = 0; j < 3; j++)
            swap(b[i][j], b[i][j + 5]);
        used[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(used[a[i]] != used[b[i]]){
            cout << "contest" << endl;
            return;
        }
    }
    cout << "home" << endl;
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