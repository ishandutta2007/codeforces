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

string s;
char c;

int main()
{
    cin >> s;
    for( int i = 1; i < s.size() - 1; i++ ){
        if( s[i] == s[i - 1] && s[i] == s[i + 1] ){
            char c = 'a';
            while( c == s[i - 1] || c == s[i + 1] )
                c++;
            s[i] = c;
        }
    }
    for( int i = 1; i < s.size(); i++ ){
        if( s[i] == s[i - 1] ){
            char c = 'a';
            while( c == s[i - 1] || c == s[i + 1] )
                c++;
            s[i] = c;
        }
    }
    cout << s << endl;
}