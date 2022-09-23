#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int a[N];
int r[N];
bool used[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i < N; i++){
                a[i] = i;
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(used[x]){
                        cout << a[x] << " ";
                        continue;
                }
                for(int j = max(0, x - k + 1); j <= x; j++){
                        if(a[j] == j){
                                int g = a[j];
                                while(j <= x){
                                        used[j] = 1;
                                        a[j] = g;
                                        j++;
                                }
                        }
                }
                cout << a[x] << " ";
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