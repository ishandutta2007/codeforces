#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int x1;
int x2;
pair < int, int > p[N];

void solve()
{
        cin >> n >> x1 >> x2;
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi;
                p[i].se = i;
        }
        sort(p + 1, p + n + 1);
        for(int i = n - 1; i >= 1; i--){
                int k1 = (x1 - 1) / p[i].fi + 1;
                if(i + k1 - 1 < n){
                        int k2 = n - i + 1 - k1;
                        if((x2 - 1) / p[i + k1].fi + 1 <= k2){
                                cout << "Yes" << "\n";
                                cout << k1 << " " << k2 << "\n";
                                for(int j = 0; j < k1; j++){
                                        cout << p[i + j].se << " ";
                                }
                                cout << "\n";
                                for(int j = 0; j < k2; j++){
                                        cout << p[i + k1 + j].se << " ";
                                }
                                return;
                        }
                }
                int k2 = (x2 - 1) / p[i].fi + 1;
                if(i + k2 - 1 < n){
                        int k1 = n - i + 1 - k2;
                        if((x1 - 1) / p[i + k2].fi + 1 <= k1){
                                cout << "Yes" << "\n";
                                cout << k1 << " " << k2 << "\n";
                                for(int j = 0; j < k1; j++){
                                        cout << p[i + k2 + j].se << " ";
                                }
                                cout << "\n";
                                for(int j = 0; j < k2; j++){
                                        cout << p[i + j].se << " ";
                                }
                                return;
                        }
                }
        }
        cout << "No" << "\n";
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