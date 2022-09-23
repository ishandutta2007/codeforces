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

int n, k;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(5 - x >= k)
            cnt++;
    }
    cout << cnt / 3 << endl;
}