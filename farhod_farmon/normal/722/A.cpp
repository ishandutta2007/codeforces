#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int t, x, y, ax, ay;
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> t;
    cin >> s;
    x = (s[3] - '0') * 10 + s[4] - '0';
    if(x > 59)
        s[3] = '0';
    x = (s[0] - '0') * 10 + s[1] - '0';
    if(t == 12){
        if(x < 1)
            s[0] = '1';
        else if(x > 12){
            if(s[1] == '0')
                s[0] = '1';
            else
                s[0] = '0';
        }
    }
    else{
        if(x > 23)
            s[0] = '0';
    }
    cout << s << endl;
}