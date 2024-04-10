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

map < string, int > hsh;
int n, m;
int L[N];
int LR[N];
string a[N];
vector < int > v[N];
int G;

void op(string &s)
{
    for(int i = 0; i < s.size(); i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    if(!hsh[s])
        hsh[s] = ++G;
    else
        return;
    int g = hsh[s];
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'r')
            LR[g]++;
    }
    L[g] = s.size();
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        op(a[i]);
    }
    cin >> m;
    set < pair < int, int > > s;
    for(int i = 1; i <= m; i++){
        string s, t;
        cin >> s >> t;
        op(s);
        op(t);
        v[hsh[t]].pb(hsh[s]);
    }
    for(int i = 1; i <= G; i++)
        s.insert({LR[i], i});
    while(!s.empty()){
        int x = s.begin()->se;
        s.erase(s.begin());
        for(auto y: v[x]){
            if(LR[x] < LR[y] || LR[x] == LR[y] && L[x] < L[y]){
                s.erase({LR[y], y});
                LR[y] = LR[x];
                L[y] = L[x];
                s.insert({LR[y], y});
            }
        }
    }
    long long l = 0,
              lr = 0;
    for(int i = 1; i <= n; i++){
        l += L[hsh[a[i]]];
        lr += LR[hsh[a[i]]];
    }
    cout << lr << " " << l << endl;
}