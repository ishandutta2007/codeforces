#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

string s;
char c[200];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    c['A'] = 'A';
    c['H'] = 'H';
    c['I'] = 'I';
    c['O'] = 'O';
    c['X'] = 'X';
    c['Y'] = 'Y';
    c['V'] = 'V';
    c['M'] = 'M';
    c['W'] = 'W';
    c['U'] = 'U';
    c['T'] = 'T';
    c['W'] = 'W';
    for(int i = 0; i < s.size(); i++){
        if(s[i] != c[s[s.size() - i - 1]]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}