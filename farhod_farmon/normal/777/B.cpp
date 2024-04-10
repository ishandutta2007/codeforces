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
int mn;
int mx;
int a[10];
int b[10];
string s;
string t;

void solve()
{
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++)
        a[t[i] - '0']++,
        b[t[i] - '0']++;
    for(int i = 0; i < n; i++){
        for(int j = s[i] - '0'; j < 10; j++){
            if(a[j]){
                mn++;
                a[j]--;
                break;
            }
        }
        for(int j = s[i] - '0' + 1; j < 10; j++){
            if(b[j]){
                mx++;
                b[j]--;
                break;
            }
        }
    }
    cout << n - mn << " " << mx << endl;
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