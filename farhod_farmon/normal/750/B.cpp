#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
int x;
int t;
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t >> s;
        if(x == 0 && s != "South" || x == 20000 && s != "North"){
            cout << "NO" << endl;
            return 0;
        }
        if(s == "South"){
            if(x + t > 20000){
                cout << "NO" << endl;
                return 0;
            }
            x += t;
        }
        if(s == "North"){
            if(x - t < 0){
                cout << "NO" << endl;
                return 0;
            }
            x -= t;
        }
    }
    if(x == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}