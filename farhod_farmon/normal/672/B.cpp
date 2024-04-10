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
bool used[200];

int main()
{
    cin >> n >> s;
    if(n > 26){
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += !used[s[i]];
        used[s[i]]++;
    }
    cout << n - cnt << endl;
}