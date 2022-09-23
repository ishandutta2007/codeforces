#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

int n, m;
int a[N];
pair < int, int > p[111];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i++)
        a[p[i].se] = i % 2;
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}