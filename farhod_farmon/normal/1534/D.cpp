#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 1e9 + 7;

using namespace std;

int n;
vector < int > d[N];

void get(int x)
{
        if(d[x].empty()){
                cout << "? " << x + 1 << endl;
                d[x].resize(n);
                for(int i = 0; i < n; i++){
                        cin >> d[x][i];
                }
        }
}

set < pair < int, int > > edges;

void add(int x, int y)
{
        if(x > y){
                swap(x, y);
        }
        edges.insert({x, y});
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        get(0);
        vector < int > A, B;
        for(int i = 0; i < n; i++){
                if(d[0][i] % 2 == 0){
                        A.push_back(i);
                } else{
                        B.push_back(i);
                }
        }
        if(B.size() < A.size()){
                swap(A, B);
        }
        for(int x: A){
                get(x);
                for(int i = 0; i < n; i++){
                        if(d[x][i] == 1){
                                add(x, i);
                        }
                }
        }
        assert(edges.size() == n - 1);
        cout << "!" << endl;
        for(auto x: edges){
                cout << x.fi + 1 << " " << x.se + 1 << endl;
        }
}