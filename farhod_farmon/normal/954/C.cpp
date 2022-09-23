#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];

void can(int m)
{
        for(int i = 2; i <= n; i++){
                int x = (a[i - 1] / m), y = (a[i - 1] % m);
                int nx = (a[i] / m), ny = (a[i] % m);
                if(abs(x - nx) + abs(y - ny) != 1){
                        return;
                }
        }
        cout << "YES" << "\n";
        cout << 1000000000 << " " << m << "\n";
        exit(0);
}

void solve()
{
        set < int > s;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i]--;
                if(i > 1){
                        if(a[i] == a[i - 1]){
                                cout << "NO" << "\n";
                                return;
                        }
                        s.insert(abs(a[i] - a[i - 1]));
                }
        }
        can(1);
        int g = 0;
        for(auto x: s){
                if(g == 3){
                        break;
                }
                else{
                        g++;
                        can(x);
                }
        }
        cout << "NO" << "\n";
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