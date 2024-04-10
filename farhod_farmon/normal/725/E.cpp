#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n, c;
int col[N];
vector < int > v;

void solve(int x)
{
    int l = v.size() - 1;
    int cc = c;
    int ff = x;
    while(cc){
        int g = lower_bound(v.begin(), v.end(), min(v[l] - 1, cc)) - v.begin();
        while(g >= 0 && v[g] > min(v[l] - 1, cc))
            g--;
        if(g == -1)
            break;
        if(v[g] <= x && x <= cc){
            cc -= x;
            x = -1;
        }
        else{
            cc -= min(cc / v[g], col[v[g]]) * v[g];
            l = g;
        }
    }
    if(cc){
        cout << ff << endl;
        exit(0);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> c >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(col[x] == 0)
            v.pb(x);
        col[x]++;
    }
    sort(v.begin(), v.end());
    v.pb(1e9);
    for(int i = 1; i <= c; i++)
        solve(i);
    cout << "Greed is good" << endl;
}