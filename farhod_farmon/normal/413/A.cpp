#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5000000;

using namespace std;

int n, m, mn, mx;
bool a, b;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> mn >> mx;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if(x < mn || x > mx){
            cout << "Incorrect" << endl;
            return 0;
        }
        if(x == mn)
            a = true;
        if(x == mx)
            b = true;
    }
    if(m + 2 - a - b <= n){
        cout << "Correct" << endl;
    }
    else{
        cout << "Incorrect" << endl;
    }
    return 0;
}