#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

char c[200];
string s, t;
bool used[200];
vector < pair < char, char > > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    for(int i = 'a'; i <= 'z'; i++)
        c[i] = i;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != c[t[i]]){
            if(used[s[i]] || used[t[i]]){
                cout << -1 << endl;
                return 0;
            }
            used[s[i]] = true;
            used[t[i]] = true;
            v.pb({s[i], t[i]});
            swap(c[s[i]], c[t[i]]);
        }
        else
            used[s[i]] = true;
    }
    cout << v.size() << endl;
    for(auto x: v)
        cout << x.fi << " " << x.se << endl;
}