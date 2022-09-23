#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n;
string s[1001];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    bool b = false;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(b)
            continue;
        if(s[i][0] == s[i][1] && s[i][0] == 'O'){
            b = true;
            s[i][0] = '+';
            s[i][1] = '+';
        }
        else if(s[i][3] == s[i][4] && s[i][3] == 'O'){
            b = true;
            s[i][3] = '+';
            s[i][4] = '+';
        }
    }
    if(!b){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << s[i] << endl;
}