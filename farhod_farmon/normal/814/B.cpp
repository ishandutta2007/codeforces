#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int p[N];
int used[N];

int get()
{
        int cnt = 0, h;
        for(int i = 1; i <= n; i++){
                if(used[i] == 0){
                        cnt++;
                        h = i;
                }
        }
        if(cnt != 1){
                return -1;
        }
        return h;
}

void upd(int x, int g)
{
        used[x] += g;
}

void make()
{
        int c1 = 0, c2 = 0;
        for(int i = 1; i <= n; i++){
                c1 += (a[i] != p[i]);
                c2 += (b[i] != p[i]);
        }
        if(c1 == 1 && c2 == 1){
                for(int i = 1; i <= n; i++){
                        cout << p[i] << " ";
                }
                exit(0);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                upd(a[i], 1);
                p[i] = a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
                upd(a[i], -1);
                p[i] = get();
                if(p[i] != -1){
                        make();
                }
                p[i] = a[i];
                upd(a[i], 1);
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("cowjog.in");
        //fout("cowjog.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}