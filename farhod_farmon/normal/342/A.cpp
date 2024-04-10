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

int n, d[8], i, j, h, x;
vector < string > v;

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> x;
        d[x]++;
    }
    while(d[1] && d[2] && d[4]){
        d[1]--, d[2]--, d[4]--;
        v.pb("1 2 4");
    }
    while(d[1] && d[3] && d[6]){
        d[1]--, d[3]--, d[6]--;
        v.pb("1 3 6");
    }
    while(d[1] && d[2] && d[6]){
        d[1]--, d[2]--, d[6]--;
        v.pb("1 2 6");
    }
    for(i = 1; i <= 7; i++){
        if(d[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    for(i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}