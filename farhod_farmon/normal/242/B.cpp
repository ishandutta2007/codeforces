#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int h,
        tl = 1e9,
        tr = 0,
        mn = 1e9,
        mx = 0;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        mn = min(mn, l);
        mx = max(mx, r);
        if(l < tl){
            tl = l;
            tr = r;
            h = i;
        }
        else if(l == tl && r > tr){
            tl = l;
            tr = r;
            h = i;
        }
    }
    if(tl <= mn && mx <= tr)
        cout << h << endl;
    else
        cout << -1 << endl;
}