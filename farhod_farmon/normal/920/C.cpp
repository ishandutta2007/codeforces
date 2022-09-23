#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];
string s;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        cin >> s;
        for(int i = 1; i <= n; i++){
                int l = 1;
                while(i + l <= n && s[i + l - 2] == '1'){
                        l++;
                }
                sort(a + i, a + i + l);
                for(int j = i; j < i + l; j++){
                        if(a[j] != j){
                                cout << "NO" << "\n";
                                return;
                        }
                }
                i += l - 1;
        }
        cout << "YES" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}