#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400400;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int r[N];
int last[N];
bool used[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--){
                r[i] = last[a[i]];
                last[a[i]] = i;
        }
        set < pair < int, int > > s;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                if(used[a[i]]){
                        auto x = s.find({i, a[i]});
                        s.erase(x);
                        if(r[i] == 0){
                                used[a[i]] = false;
                        }
                        else{
                                s.insert({r[i], a[i]});
                        }
                        continue;
                }
                cnt++;
                if(s.size() == k){
                        auto x = (--s.end());
                        used[x->se] = false;
                        s.erase(x);
                }
                if(r[i]){
                        used[a[i]] = true;
                        s.insert({r[i], a[i]});
                }
        }
        cout << cnt << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}