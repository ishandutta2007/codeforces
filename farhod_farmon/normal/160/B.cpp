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

bool a = true, b = true;
string s;
int n;

int main()
{
    cin >> n >> s;
    sort(s.begin(), s.end() - n);
    sort(s.begin() + n, s.end());
    for(int i = 0; i < n; i++){
        a &= s[i] < s[n + i];
        b &= s[i] > s[n + i];
    }
    if(a || b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}