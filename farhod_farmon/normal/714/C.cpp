#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

map < string, int > d;

void add(string s, int x)
{
    string t = "";
    for(int i = 0; i < 18 - s.size(); i++)
        t += '0';
    for(int i = 0; i < s.size(); i++)
        t += char('0' + (s[i] - '0') % 2);
    d[t] += x;
}

int kol(string s)
{
    string t = "";
    for(int i = 0; i < 18 - s.size(); i++)
        t += '0';
    t += s;
    return d[t];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        char c;
        string x;
        cin >> c >> x;
        if(c == '+')
            add(x, 1);
        else if(c == '-')
            add(x, -1);
        else
            cout << kol(x) << endl;
    }
}