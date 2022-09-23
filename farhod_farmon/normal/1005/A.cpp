#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];

void solve()
{
        vector < int > v;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(i > 1 && a[i] == 1){
                        v.push_back(a[i - 1]);
                }
        }
        v.push_back(a[n]);
        cout << v.size() << "\n";
        for(int x: v){
                cout << x << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}