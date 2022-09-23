#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n;

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    int cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt += x;
    }
    if(cnt == max(1, n - 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}