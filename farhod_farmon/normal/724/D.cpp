
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

vector < int > v[200];
char c[N];
int n, m;
set < int > s;

void solve(int x)
{
    vector < int > g;
    for(auto &p: s)
        g.pb(p);
    int j = 0;
    for(int i = 0; i + 1 < g.size(); i++){
        if(g[i] + m >= g[i + 1])
            continue;
        while(j < v[x].size() && v[x][j] < g[i])
            j++;
        if(j == v[x].size())
            break;
        int y = g[i];
        while(y + m < g[i + 1] && j < v[x].size()){
            while(j + 1 < v[x].size() && v[x][j + 1] <= y + m)
                j++;
            y = v[x][j];
            s.insert(y);
            j++;
        }
    }
}

bool cor()
{
    vector < int > g;
    for(auto &p: s)
        g.pb(p);
    for(int i = 1; i < g.size(); i++){
        if(g[i - 1] + m < g[i])
            return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d\n%s", &m, &c);
    n = strlen(c);
    for(int i = 0; i < n; i++)
        v[c[i]].pb(i);
    s.insert(-1);
    s.insert(n);
    for(int i = 'a'; i <= 'z'; i++){
        if(v[i].empty())
            continue;
        solve(i);
        if(cor()){
            break;
        }
        else{
            for(int j = 0; j < v[i].size(); j++)
                s.insert(v[i][j]);
        }
    }
    string ans = "";
    for(auto &p: s){
        if(p >= 0 && p < n)
            ans += c[p];
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        pr("%c", ans[i]);
}