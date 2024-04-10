#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2000010;
const long long mod = 1e9 + 7;

using namespace std;

int n;
string t[100100];
vector < int > v[N];
char c[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int l;
                cin >> t[i] >> l;
                for(int j = 1; j <= l; j++){
                        int k;
                        cin >> k;
                        v[k].push_back(i);
                }
        }
        int r = 0;
        for(int i = 1; i < N; i++){
                if(v[i].empty()){
                        continue;
                }
                for(int k: v[i]){
                        int g = max(0, r + 1 - i);
                        r = max(r, i + (int)t[k].size() - 1);
                        for(int j = g; j < t[k].size(); j++){
                                c[i + j] = t[k][j];
                        }
                }
        }
        for(int i = 1; i <= r; i++){
                if(!c[i]){
                        c[i] = 'a';
                }
                cout << c[i];
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}