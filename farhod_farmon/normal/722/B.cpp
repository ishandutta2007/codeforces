#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 303;

using namespace std;

int f[200];
int n, p[200];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    f['a'] = 1;
    f['e'] = 1;
    f['i'] = 1;
    f['o'] = 1;
    f['u'] = 1;
    f['y'] = 1;
    bool ans = true;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    int h = 0;
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        if(h == 0){
            i = 0;
            h = 1;
            continue;
        }
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' ')
                continue;
            p[i] -= f[s[j]];
        }
        if(p[i] != 0)
            ans = false;
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}