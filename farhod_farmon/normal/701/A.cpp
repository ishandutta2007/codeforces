#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n;
pair < int, int > p[101];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n / 2; i++)
        cout << p[i].se << " " << p[n - i + 1].se << endl;
}