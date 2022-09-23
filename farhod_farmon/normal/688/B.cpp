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

const int N = 755;

using namespace std;

string s;

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << endl;
}