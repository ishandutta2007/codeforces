#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
long long a[N];
set < long long > s;
unordered_map < long long, set < int > > used;

void upd(long long x, int g)
{
        if(g == 1){
                used[a[x]].insert(x);
                if(used[a[x]].size() == 2){
                        s.insert(a[x]);
                }
        }
        else{
                used[a[x]].erase(x);
                if(used[a[x]].size() == 1){
                        s.erase(a[x]);
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                upd(i, 1);
        }
        while(!s.empty()){
                long long x = *s.begin();
                int f1 = *used[x].begin(); upd(f1, -1);
                int f2 = *used[x].begin(); upd(f2, -1);
                a[f1] = -1;
                a[f2] += a[f2];
                upd(f2, 1);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                cnt += a[i] != -1;
        }
        cout << cnt << "\n";
        for(int i = 1; i <= n; i++){
                if(a[i] != -1){
                        cout << a[i] << " ";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}