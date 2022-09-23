#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;

bool check(int x, int y)
{
        cout << 1 << " " << x << " " << y << endl;
        fflush(stdout);
        string s;
        cin >> s;
        if(s == "TAK"){
                return 1;
        }
        return 0;
}

int get(int l, int r)
{
        if(l > r){
                return -1;
        }
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        if(check(m, m + 1)){
                return get(l, m);
        }
        else{
                return get(m + 1, r);
        }
}

void solve()
{
        cin >> n >> k;
        int x = get(1, n);
        int y = get(1, x - 1);
        if(y == -1 || check(y, x) == false){
                y = get(x + 1, n);
        }
        cout << 2 << " " << x << " " << y << endl;
        fflush(stdout);
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}