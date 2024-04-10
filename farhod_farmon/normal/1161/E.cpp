#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;

string query(vector < pair < int, int > > v)
{
        if(v.empty()){
                return "";
        }
        cout << "Q " << v.size();
        for(auto p: v){
                cout << " " << p.fi << " " << p.se;
        }
        cout << endl;
        string res;
        cin >> res;
        return res;
}

int a[N];
int p[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                a[i] = 0;
                p[i] = i;
        }
        vector < vector < int > > group;
        for(int it: {2, 1}){
                vector < pair < int, int > > v;
                for(int i = it; i + 1 <= n; i += 2){
                        v.push_back({i, i + 1});
                }
                string s = query(v);
                for(int i = 0; i < v.size(); i++){
                        int x = v[i].fi, y = v[i].se;
                        if(s[i] == '1'){
                                x = get(x);
                                y = get(y);
                                p[x] = y;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                if(i == 1){
                        group.push_back({i});
                        continue;
                }
                if(get(i) == get(i - 1)){
                        group.back().push_back(i);
                } else{
                        group.push_back({i});
                }
        }
        if(group.size() > 1){
                for(int x: group[0]){
                        a[x] = 1;
                }
                for(int x: group[1]){
                        a[x] = 2;
                }
        }
        vector < int > eq((int)group.size());
        for(int it: {0, 1}){
                for(int it2: {0, 2}){
                        vector < pair < int, int > > v;
                        for(int i = it + it2; i + 2 < group.size(); i += 4){
                                v.push_back({group[i][0], group[i + 2][0]});
                        }
                        string s = query(v);
                        for(int i = it + it2, j = 0; i + 2 < group.size(); i += 4, j += 1){
                                eq[i] = s[j] - '0';
                        }
                }
        }
        for(int i = 2; i < group.size(); i++){
                int x = group[i - 1][0], y = group[i - 2][0];
                if(eq[i - 2]){
                        for(int z: group[i]){
                                a[z] = a[y];
                        }
                } else{
                        for(int z: group[i]){
                                a[z] = 6 - a[x] - a[y];
                        }
                }
        }
        vector < int > A, B, C;
        for(int i = 1; i <= n; i++){
                if(a[i] == 1){
                        A.push_back(i);
                } else if(a[i] == 2){
                        B.push_back(i);
                } else{
                        C.push_back(i);
                }
        }
        cout << "A " << A.size() << " " << B.size() << " " << C.size() << endl;
        for(int x: A){
                cout << x << " ";
        }
        cout << endl;
        for(int x: B){
                cout << x << " ";
        }
        cout << endl;
        for(int x: C){
                cout << x << " ";
        }
        cout << endl;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}