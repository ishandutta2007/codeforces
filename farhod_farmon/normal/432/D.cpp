#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int z[N];
string s;
vector < int > v, ans;

int get(int g)
{
    int l = 0,
        r = v.size();
    while(l < r){
        int m = (l + r) / 2;
        if(v[m] < g)
            l = m + 1;
        else
            r = m;
    }
    return v.size() - l;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    for(int i = 1, l = 0, r = 0; i < s.size(); i++){
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(z[i] + i - 1 > r){
            l = i;
            r = z[i] + i - 1;
        }
    }
    ans.pb(s.size());
    for(int i = 1; i < s.size(); i++){
        v.pb(z[i]);
        if(i + z[i] == s.size())
            ans.pb(z[i]);
    }
    sort(v.begin(), v.end());
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " " << get(ans[i]) + 1 << endl;
}