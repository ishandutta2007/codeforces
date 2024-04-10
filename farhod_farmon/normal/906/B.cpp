#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 60100;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n, m;
vector < vector < int > > v;

void solve()
{
        cin >> n >> m;
        v.resize(n);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        v[i].push_back(i * m + j + 1);
                }
        }
        if(n == 1 && m == 1){
                cout << "YES" << "\n";
                cout << 1 << "\n";
                return;
        }
        if(n == 3 && m == 3){
                cout << "YES" << "\n";
                cout << "8 1 6\n";
                cout << "3 5 7\n";
                cout << "4 9 2\n";
                return;
        }
        if(max(n, m) <= 3){
                cout << "NO" << "\n";
                return;
        }
        cout << "YES" << "\n";
        if(n >= m){
                vector < int > g0, g1;
                for(int i = 2; i < n; i += 2)g0.push_back(i);
                g0.push_back(0); g0.push_back(3); g0.push_back(1);
                for(int i = 5; i < n; i += 2)g0.push_back(i);
                if(n % 2 == 1){
                        for(int i = n - 2; i >= 0; i -= 2)g1.push_back(i);
                        for(int i = n - 1; i >= 0; i -= 2)g1.push_back(i);
                }
                else{
                        for(int i = 1; i < n; i += 2)g1.push_back(i);
                        for(int i = 0; i < n; i += 2)g1.push_back(i);
                }
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                                if(j % 2 == 0)cout << v[g0[i]][j] << " ";
                                else cout << v[g1[i]][j] << " ";
                        }
                        cout << "\n";
                }
        }
        else{
                vector < int > g0, g1;
                for(int i = 2; i < m; i += 2)g0.push_back(i);
                g0.push_back(0); g0.push_back(3); g0.push_back(1);
                for(int i = 5; i < m; i += 2)g0.push_back(i);
                if(m % 2 == 1){
                        for(int i = m - 2; i >= 0; i -= 2)g1.push_back(i);
                        for(int i = m - 1; i >= 0; i -= 2)g1.push_back(i);
                }
                else{
                        for(int i = 1; i < m; i += 2)g1.push_back(i);
                        for(int i = 0; i < m; i += 2)g1.push_back(i);
                }
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                                if(i % 2 == 0)cout << v[i][g0[j]] << " ";
                                else cout << v[i][g1[j]] << " ";
                        }
                        cout << "\n";
                }
        }
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