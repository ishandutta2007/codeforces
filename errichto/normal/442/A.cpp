#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

string wzor = "RGBYW";
int t[105][2];
int razem[105];
bool tak[10];
set<int> s[10];
set<int> zupa;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    RE(i, n) {
        char inp[3];
        cin >> inp;
        RE(j, 5) if(inp[0] == wzor[j]) t[i][0] = j;
        t[i][1] = inp[1] - '1';
        razem[i] = t[i][0] * 5 + t[i][1];
    }

    int M = 1 << 10;
    int res = 10000;
    RE(mask, M) {
        RE(i, 10) s[i].clear();
        zupa.clear();
        int x = mask;
        int ile = 0;
        RE(i, 10) {
            tak[i] = (x % 2 == 1);
            if(tak[i]) ile++;
            x /= 2;
        }
        RE(i, n) {
            bool raz = tak[ t[i][0] ];
            bool dwa = tak[ 5 + t[i][1] ];
            if(raz && (!dwa)) s[ t[i][0] ].insert( t[i][1] );
            if((!raz) && dwa) s[ 5 + t[i][1] ].insert (t[i][0]);
            if(!(raz || dwa)) zupa.insert(razem[i]);
        }
        bool ok = true;
        RE(i, 10) if(s[i].size() > 1) ok = false;
        if(zupa.size() > 1) ok = false;
        if(ok) mini(res, ile);
    }
    cout << res;

    return 0;
}