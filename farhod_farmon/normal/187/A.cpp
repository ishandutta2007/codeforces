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

int a[N], b[N], n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        b[x] = i;
    }
    int last = 0,
        cnt = 0;
    for(int i = 1; i <= n; i++){
        if(b[a[i]] < last)
            break;
        last = b[a[i]];
        cnt++;
    }
    cout << n - cnt << endl;
}