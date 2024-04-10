#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1001;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int l[N];
int r[N];
bool used[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> l[i] >> r[i];
        }
        int x = -1, y = -1;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                int tl, tr;
                for(int j = i; j; j = l[j]){
                        used[j] = 1;
                        tl = j;
                }
                for(int j = i; j; j = r[j]){
                        used[j] = 1;
                        tr = j;
                }
                if(y != -1){
                        r[y] = tl;
                        l[tl] = y;
                }
                x = tl;
                y = tr;
        }
        for(int i = 1; i <= n; i++){
                cout << l[i] << " " << r[i] << "\n";
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