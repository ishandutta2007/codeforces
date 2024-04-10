#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1001;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;

void solve()
{
        cin >> n;
        vector < vector < int > > v;
        v.push_back({0});
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                int l = 0, r = v.size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(x > v[m].back()){
                                r = m;
                        }
                        else{
                                l = m + 1;
                        }
                }
                v[l].push_back(x);
                if(l == v.size() - 1){
                        v.push_back({0});
                }
        }
        for(int i = 0; i < v.size() - 1; i++){
                for(int j = 1; j < v[i].size(); j++){
                        cout << v[i][j] << " ";
                }
                cout << "\n";
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