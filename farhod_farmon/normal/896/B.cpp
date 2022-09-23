#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 1000010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;
int m;
int c;
int a[N];

bool cor()
{
        for(int i = 1; i <= n; i++){
                if(!a[i]){
                        return false;
                }
                if(i > 1 && a[i - 1] > a[i]){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n >> m >> c;
        while(m){
                m--;
                int x;
                cin >> x;
                if(x <= (c + 1) / 2){
                        int h = -1;
                        for(int i = 1; i <= n; i++){
                                if(a[i] == 0 || x < a[i]){
                                        h = i;
                                        break;
                                }
                        }
                        a[h] = x;
                        cout << h << endl;
                }
                else{
                        int h = -1;
                        for(int i = n; i >= 1; i--){
                                if(a[i] == 0 || x > a[i]){
                                        h = i;
                                        break;
                                }
                        }
                        a[h] = x;
                        cout << h << endl;
                }
                if(cor()){
                        break;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}