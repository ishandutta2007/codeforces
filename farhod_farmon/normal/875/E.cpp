#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int s1;
int s2;
int a[N];
int L[N];
int mn[N][20];
int mx[N][20];

pair < int, int > get(int l, int r)
{
        int g = L[r - l + 1];
        return {min(mn[l][g], mn[r - (1 << g) + 1][g]), max(mx[l][g], mx[r - (1 << g) + 1][g])};
}

bool can(int mi)
{
        if(abs(s1 - s2) > mi){
                return false;
        }
        int mx = 0;
        for(int i = 1; i <= n; i++){
                if(abs(s1 - a[i]) <= mi){
                        mx = i;
                }
                else{
                        break;
                }
        }
        for(int i = 1; i <= n; i++){
                if(abs(s2 - a[i]) <= mi){
                        mx = max(mx, i);
                }
                else{
                        break;
                }
        }
        for(int i = 1; i <= n; i++){
                if(mx < i){
                        return false;
                }
                int l = i, r = n;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        pair < int, int > p = get(i, m);
                        if(p.fi >= a[i] - mi && p.se <= a[i] + mi){
                                l = m;
                        }
                        else{
                                r = m - 1;
                        }
                }
                mx = max(mx, l);
        }
        return true;
}

void solve()
{
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        cin >> n >> s1 >> s2;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                mn[i][0] = mx[i][0] = a[i];
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 <= n){
                                mn[j][i] = min(mn[j][i - 1], mn[j + (1 << i) / 2][i - 1]);
                                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << i) / 2][i - 1]);
                        }
                }
        }
        int l = 0, r = 1e9 + 10;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
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