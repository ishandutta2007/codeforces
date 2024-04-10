#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const ll N = 500100;
const ll MX = 1e16;
const ll MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int en[N];
vector < string > v;

void solve()
{
    cin >> n;
    v.resize(n + 2, "");
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        en[i] = v[i].size();
    }
    for(int i = n - 1; i >= 0; i--){
        bool eq = true;
        bool sm = false;
        int h;
        for(int j = 1; j < min(en[i], en[i + 1]); j++){
            if(v[i][j] != v[i + 1][j]){
                if(v[i][j] < v[i + 1][j])
                    sm = true;
                else
                    h = j;
                eq = false;
                break;
            }
        }
        if(eq){
            en[i] = min(en[i], en[i + 1]);
            continue;
        }
        else if(sm == false)
            en[i] = h;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < en[i]; j++)
            cout << v[i][j];
        cout << "\n";
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