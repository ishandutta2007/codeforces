#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr prlong longf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int cnt = 0,
        s = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == -1)
            s--;
        else
            s += x;
        if(s == -1)
            cnt++,
            s = 0;
    }
    cout << cnt << endl;
}