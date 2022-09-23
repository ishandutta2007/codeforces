#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

char c[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};
string s;

bool f(char x)
{
    for(int i = 0; i < 6; i++)
        if(x == c[i])
            return true;
    return false;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    int mx = 0;
    s = 'A' + s + 'A';
    for(int i = 0; i + 1 < s.size(); i++){
        int g = 1;
        while(!f(s[i + g]))
            g++;
        mx = max(mx, g);
        i += g - 1;
    }
    cout << mx << endl;
}