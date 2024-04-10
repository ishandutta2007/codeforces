#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int a[55];

bool can()
{
        for(int i = 1; i <= 24; i += 4){
                if(a[i] != a[i + 1] || a[i] != a[i + 2] || a[i] != a[i + 3]){
                        return false;
                }
        }
        return true;
}

void f(int x1, int x2, int x3, int x4, int g1, int g2)
{
        swap(a[x1], a[x2]);
        swap(a[x1 + g1], a[x2 + g2]);
        swap(a[x2], a[x3]);
        swap(a[x2 + g2], a[x3 + g1]);
        swap(a[x3], a[x4]);
        swap(a[x3 + g1], a[x4 + g2]);
        if(can()){
                cout << "YES" << "\n";
                exit(0);
        }
        swap(a[x3], a[x4]);
        swap(a[x3 + g1], a[x4 + g2]);
        swap(a[x2], a[x3]);
        swap(a[x2 + g2], a[x3 + g1]);
        swap(a[x1], a[x2]);
        swap(a[x1 + g1], a[x2 + g2]);
}

void solve()
{
        for(int i = 1; i <= 24; i++){
                cin >> a[i];
        }
        f(1, 5, 9, 22, 2, 2);
        f(2, 6, 10, 21, 2, 2);
        f(13, 5, 17, 21, 1, 1);
        f(15, 7, 19, 23, 1, 1);
        f(9, 17, 3, 14, 1, 2);
        f(11, 18, 1, 13, 1, 2);
        cout << "NO" << "\n";
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