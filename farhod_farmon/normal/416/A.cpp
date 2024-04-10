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

int l = -1e9 - 2, r = 1e9 + 2;
int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        int x;
        char c;
        cin >> s >> x >> c;
        if(c == 'N'){
            if(s == ">=")
                s = "<";
            else if(s == "<=")
                s = ">";
            else if(s == ">")
                s = "<=";
            else if(s == "<")
                s = ">=";
        }
        if(s == ">=")
            l = max(l, x);
        if(s == "<=")
            r = min(r, x);
        if(s == ">")
            l = max(l, x + 1);
        if(s == "<")
            r = min(r, x - 1);
    }
    if(l > r)
        cout << "Impossible" << endl;
    else
        cout << l << endl;
}