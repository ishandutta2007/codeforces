#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int m;
int v;
vector < int > a, b;

void solve()
{
        int l1, l2;
        cin >> n >> m >> l1 >> l2 >> v;
        a.resize(l1 + 1, 0);
        b.resize(l2 + 1, 0);
        for(int i = 1; i <= l1; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= l2; i++){
                cin >> b[i];
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                if(y1 > y2){
                        swap(x1, x2);
                        swap(y1, y2);
                }
                if(x1 == x2){
                        cout << y2 - y1 << "\n";
                        continue;
                }
                int ans = 1e9;
                if(a.size() > 1){
                        int l = 1, r = a.size() - 1;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(a[m] > y1){
                                        r = m;
                                }
                                else{
                                        l = m + 1;
                                }
                        }
                        for(int j = -1; j <= 1; j++){
                                if(l + j < 1 || l + j >= a.size()){
                                        continue;
                                }
                                int g = a[l + j];
                                ans = min(ans, abs(y1 - g) + abs(g - y2) + abs(x1 - x2));
                        }
                }
                if(b.size() > 1){
                        int l = 1, r = b.size() - 1;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(b[m] > y1){
                                        r = m;
                                }
                                else{
                                        l = m + 1;
                                }
                        }
                        for(int j = -1; j <= 1; j++){
                                if(l + j < 1 || l + j >= b.size()){
                                        continue;
                                }
                                int g = b[l + j];
                                ans = min(ans, abs(y1 - g) + abs(g - y2) + (abs(x1 - x2) - 1) / v + 1);
                        }
                }
                cout << ans << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}