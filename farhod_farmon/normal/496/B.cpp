#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

string ans;
int n;
map < string, bool > used;

void dfs(string s)
{
    if(used[s])
        return;
    used[s] = true;
    ans = min(ans, s);
    string t = s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '9')
            s[i] = '0';
        else
            s[i]++;
    }
    for(int i = s.size() - 1; i > 0; i--)
        swap(t[i], t[i - 1]);
    dfs(s);
    dfs(t);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    string s;
    cin >> n >> s;
    ans = s;
    dfs(s);
    cout << ans << endl;
}