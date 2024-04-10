#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
long long a[N];
vector < int > v[66];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(long long j = 59; j >= 0; j--){
                        if(a[i] & (1ll << j)){
                                v[j].push_back(i);
                                break;
                        }
                }
        }
        for(long long i = 59; i >= 0; i--){
                vector < int > nv;
                if(v[i].empty()){
                        v[i] = v[i + 1];
                        continue;
                }
                nv.push_back(v[i][0]);
                int g = 1, j = 1, h = 0;
                while(j < v[i].size()){
                        if(g == 0){
                                nv.push_back(v[i][j]);
                                g = 1;
                                j++;
                        }
                        else if(h < v[i + 1].size()){
                                g ^= (a[v[i + 1][h]] >> i) & 1;
                                nv.push_back(v[i + 1][h]);
                                h++;
                        }
                        else{
                                cout << "No" << "\n";
                                return;
                        }
                }
                while(h < v[i + 1].size()){
                        nv.push_back(v[i + 1][h]);
                        h++;
                }
                v[i] = nv;
        }
        cout << "Yes" << "\n";
        for(int x: v[0]){
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