#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

int n;
int k;
int d[N][N];
int l[N][N];
int b[N][N];
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s >> k;
    n = s.size();
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            int cnt = 0;
            for(int h = i; h <= (i + j) / 2; h++)
                if(s[h] != s[j - (h - i)])
                    cnt++;
            b[i][j] = cnt;
        }
    }
    for(int i = 0; i < s.size(); i++){
        d[1][i] = b[0][i];
        l[1][i] = i;
    }
    for(int i = 2; i <= k; i++){
        for(int j = 0; j < s.size(); j++){
            d[i][j] = 1e5;
            for(int h = 0; h < j; h++){
                if(d[i][j] > d[i - 1][j - h - 1] + b[j - h][j]){
                    d[i][j] = d[i - 1][j - h - 1] + b[j - h][j];
                    l[i][j] = h;
                }
            }
        }
    }
    int x = 1,
        y = s.size() - 1;
    for(int i = 1; i <= k; i++)
        if(d[x][y] > d[i][y])
            x = i;
    cout << d[x][y] << endl;
    string ans = "";
    while(x){
        string t = "";
        for(int j = y; j >= y - l[x][y]; j--)
            t += s[j];
        for(int i = 0; i < t.size() / 2; i++)
            t[i] = t[t.size() - i - 1];
        ans += t;
        y = y - l[x][y] - 1;
        x = x - 1;
        if(x > 0)
            ans += '+';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}