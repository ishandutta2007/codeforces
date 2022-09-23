#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[24];
vector < int > v;
int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < 1100; i++){
                if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
                        d[1] = 29;
                }
                else{
                        d[1] = 28;
                }
                for(int j = 0; j < 12; j++){
                        v.push_back(d[j]);
                }
        }
        for(int i = 0; i + n - 1 < v.size(); i++){
                bool co = true;
                for(int j = 0; j < n; j++){
                        if(a[j] != v[i + j]){
                                co = false;
                        }
                }
                if(co){
                        cout << "YES" << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
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