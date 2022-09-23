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

int n;
string s;

int main()
{
    cin >> n;
    for(int i = 1; i <= 1000; i++){
        int x = i;
        string t = "";
        while(x){
            t += x % 10 + '0';
            x /= 10;
        }
        reverse(t.begin(), t.end());
        s += t;
    }
    cout << s[n - 1];
}