#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1001;
const int Q = N * N;
const int mod = 1e9 + 7;

using namespace std;

int d[N];
int shit[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int col = 1, mx = 0;
        for(int i = 2; i < N; i++){
                vector < int > v;
                int x = i;
                for(int j = 2; j * j <= x; j++){
                        while(x % j == 0){
                                v.push_back(j);
                                x /= j;
                        }
                }
                if(x > 1) v.push_back(x);
                if(v.size() == 1) continue;
                shit[i] = v[0];
        }

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                int col = 1;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        int x = shit[a[i]];
                        if(d[x] == 0){
                                d[x] = col;
                                col += 1;
                        }
                }
                cout << col - 1 << "\n";
                for(int x: a) cout << d[shit[x]] << " ";
                for(int x: a) d[shit[x]] = 0;

                cout << "\n";
        }
}