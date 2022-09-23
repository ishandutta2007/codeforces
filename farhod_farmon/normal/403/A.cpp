#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        p = 2 * n + p;
        for(int i = 1; i <= n && p; i++){
            for(int j = i + 1; j <= n && p; j++, p--)
                cout << i << " " << j << endl;
        }
    }
}