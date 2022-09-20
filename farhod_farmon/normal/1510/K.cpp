#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 4084;
const int mod = 998244353;

vector < int > f1(vector < int > v)
{
        for(int i = 0; i < v.size(); i += 2){
                swap(v[i], v[i + 1]);
        }
        return v;
}

vector < int > f2(vector < int > v)
{
        for(int i = 0; i < v.size() / 2; i++){
                swap(v[i], v[i + v.size() / 2]);
        }
        return v;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);


        int n;
        cin >> n;
        vector < int > v;
        for(int i = 0; i < n * 2; i++){
                int x;
                cin >> x;
                v.push_back(x);
        }
        map < vector < int >, int > used;
        queue < vector < int > > g;
        g.push(v);
        used[v] = 0;
        while(!g.empty()){
                v = g.front();
                g.pop();
                for(auto gg: {f1(v), f2(v)}){
                        if(used.find(gg) == used.end()){
                                used[gg] = used[v] + 1;
                                g.push(gg);
                        }
                }
        }

        for(int i = 0; i < 2 * n; i++){
                v[i] = i + 1;
        }

        if(used.find(v) == used.end()){
                cout << -1 << "\n";
        } else{
                cout << used[v] << "\n";
        }
}