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

long long n, x, cnt;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        char c;
        long long d;
        cin >> c >> d;
        if(c == '+')
            x += d;
        else{
            if(x < d)
                cnt++;
            else
                x -= d;
        }
    }
    cout << x << " " << cnt << endl;
}