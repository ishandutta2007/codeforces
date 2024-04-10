#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 30030;

using namespace std;

string s[N];
int n, cnt;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 0; i < s[1].size(); i++){
        bool b = true;
        for(int j = 1; j <= n; j++){
            if(s[j][i] != s[1][i]){
                b = false;
            }
        }
        if(b)
            cnt = i + 1;
        else
            break;
    }
    cout << cnt << endl;
}