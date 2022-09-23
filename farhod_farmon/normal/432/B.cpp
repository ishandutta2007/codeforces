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
int x[N];
int y[N];
int c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        c[x[i]]++;
    }
    for(int i = 1; i <= n; i++)
        cout << n - 1 + c[y[i]] << " " << n - 1 - c[y[i]] << endl;
}