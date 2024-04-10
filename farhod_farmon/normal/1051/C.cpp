#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
char c[N];
vector < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
                c[i] = 'A';
        }
        int cnt = 0;
        for(int i = 1; i < N; i++){
                if(v[i].size() == 1){
                        cnt ^= 1;
                        c[v[i][0]] = 'A' + cnt;
                }
        }
        for(int i = 1; i < N; i++){
                if(cnt && v[i].size() > 2){
                        for(int j = 1; j < v[i].size(); j++){
                                c[v[i][j]] = 'B';
                        }
                        cnt = 0;
                }
        }
        if(cnt){
                cout << "NO" << "\n";
                return;
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << c[i];
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