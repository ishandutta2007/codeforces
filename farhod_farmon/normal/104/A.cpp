#include <bits/stdc++.h>

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

int main()
{
    cin >> n;
    vector < int > v;
    for(int i = 1; i <= 11; i++){
        for(int j = 1; j <= 4; j++){
            if(i == 10 && j == 1)
                continue;
            v.pb(i);
        }
        if(i != 10)
            continue;
        for(int j = 1; j <= 12; j++)
            v.pb(i);
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++)
        if(v[i] + 10 == n)
            cnt++;
    cout << cnt << endl;
}