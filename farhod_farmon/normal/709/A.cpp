#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

int n, b, d;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> b >> d;
    int s = 0,
        cnt = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x > b)
            continue;
        s += x;
        if(s > d){
            s = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
}