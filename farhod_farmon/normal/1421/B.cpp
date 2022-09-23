#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 6;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        vector < vector < char > > a(n, vector < char > (n));
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cin >> a[i][j];
                }
        }
        vector < pair < int, int > > A, B;
        for(auto p: {make_pair(0, 1), make_pair(1, 0)}){
                if(a[p.fi][p.se] == '0'){
                        A.push_back(p);
                } else{
                        B.push_back(p);
                }
        }
        for(auto p: {make_pair(n - 2, n - 1), make_pair(n - 1, n - 2)}){
                if(a[p.fi][p.se] == '1'){
                        A.push_back(p);
                } else{
                        B.push_back(p);
                }
        }
        if(A.size() > B.size()){
                swap(A, B);
        }
        assert((int)A.size() <= 2);
        cout << A.size() << "\n";
        for(auto p: A){
                cout << p.fi + 1 << " " << p.se + 1 << "\n";
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}