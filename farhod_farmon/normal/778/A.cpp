#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 1e16;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int a[N];
bool used[N];
string s, t;

bool can(int n)
{
    for(int i = 1; i <= s.size(); i++)
        used[i] = false;
    for(int i = 1; i <= n; i++)
        used[a[i]] = true;
    int j = 0;
    for(int i = 0; i < t.size(); i++){
        while(j < s.size() && (used[j + 1] || t[i] != s[j]))
            j++;
        if(j == s.size())
            return false;
        j++;
    }
    return true;
}

void solve()
{
    cin >> s >> t;
    for(int i = 1; i <= s.size(); i++)
        cin >> a[i];
    int l = 0,
        r = s.size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(can(m + 1))
            l = m + 1;
        else
            r = m;
    }
    cout << l << endl;
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}