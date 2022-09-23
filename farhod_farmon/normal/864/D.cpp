#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];
set < int > p;
set < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[a[i]].insert(i);
        }
        for(int i = 1; i <= n; i++){
                if(v[a[i]].size() > 1){
                        p.insert(i);
                }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                if(v[i].size() != 0){
                        p.erase(*v[i].begin());
                        continue;
                }
                int x = *p.begin();
                p.erase(p.begin());
                v[a[x]].erase(x);
                if(v[a[x]].size() == 1){
                        p.erase(*v[a[x]].begin());
                }
                a[x] = i;
                cnt++;
        }
        cout << cnt << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
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