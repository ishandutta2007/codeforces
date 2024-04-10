#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr prlong longf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int n, t, c;
int a[N];
set < pair < int, int > > s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> t >> c;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < c; i++)
        s.insert({a[i], i});
    int cnt = 0;
    for(int i = c; i <= n; i++){
        s.erase({a[i - c], i - c});
        s.insert({a[i], i});
        if((--s.end())->fi <= t)
            cnt++;
    }
    cout << cnt << endl;
}