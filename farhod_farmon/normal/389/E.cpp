#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 105;

using namespace std;

int n, s1, s2;
vector < int > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            if(j <= m / 2)
                s1 += x;
            else if(j > (m + 1) /2 )
                s2 += x;
            else
                v.pb(x);
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        if(i % 2 == 0)
            s1 += v[(int)v.size() - i - 1];
        else
            s2 += v[(int)v.size() - i - 1];
    cout << s1 << " " << s2 << endl;
}