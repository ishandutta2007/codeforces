#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
int in;
int ans;
int l[N];
int r[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int sl = 0,
        sr = 0;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        sl += l[i];
        sr += r[i];
    }
    ans = abs(sl - sr);
    for(int i = 1; i <= n; i++){
        int nl = sl - l[i] + r[i],
            nr = sr - r[i] + l[i];
        if(abs(nl - nr) > ans){
            ans = abs(nl - nr);
            in = i;
        }
    }
    cout << in << endl;
}