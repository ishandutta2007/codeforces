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
int i;
vector < char > v;

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        if( v.size() && v.back() == s[i] )v.pop_back();
        else v.pb(s[i]);
    }
    if( v.size() )
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}