#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

long long ans = 3e18;

void f(vector < long long > v)
{
    long long cnt = 0;
    while(v[0] > 0 || v[1] > 0 || v[2] > 0){
        long long g = max(v[0], max(v[1], v[2]));
        if(g == v[2]){
            v[0] -= g;
            v[1] -= g;
            v[2] -= g;
        }
        else if(g == v[1]){
            v[0] -= g;
            v[1] -= g;
            v[2] -= g - 1;
        }
        else{
            v[0] -= g;
            v[1] -= g - 1;
            v[2] -= g - 1;
        }
    }
    ans = min(ans, - v[0] - v[1] - v[2]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    vector < long long > v(3);
    cin >> v[0] >> v[1] >> v[2];
    for(int i = 0; i < 3; i++){
        f(v);
        swap(v[0], v[1]);
        swap(v[1], v[2]);
    }
    cout << ans << endl;
}