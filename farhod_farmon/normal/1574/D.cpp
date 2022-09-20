#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10;

using namespace std;

map<vector<int>, int> id;
vector<vector<int>> i_id;
vector<int> ban;
vector<int> used;

int get_id(vector<int> v)
{
        if(id.find(v) == id.end()){
                id[v] = i_id.size();
                i_id.push_back(v);
                ban.push_back(0);
                used.push_back(0);
        }
        return id[v];
}

int n;
vector<int> a[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                int k;
                cin >> k;
                for(int j = 0; j < k; j++){
                        int x;
                        cin >> x;
                        a[i].push_back(x);
                }
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
                vector<int> v(n);
                for(int j = 0; j < n; j++){
                        cin >> v[j];
                        v[j]--;
                }
                ban[get_id(v)] = true;
        }
        vector<int> cur(n);
        for(int i = 0; i < n; i++){
                cur[i] = a[i].size() - 1;
        }
        set<pair<long long, int>> s;
        s.insert({0, get_id(cur)});
        while(true){
                int x = (--s.end())->se;
                s.erase(--s.end());

                if(!ban[x]){
                        for(int i: i_id[x]){
                                cout << i + 1 << " ";
                        }
                        cout << "\n";
                        return 0;
                }
                cur = i_id[x];
                long long sum = 0, ns;
                for(int i = 0; i < n; i++){
                        sum += a[i][cur[i]];
                }
                for(int i = 0, j; i < n; i++){
                        cur[i]--;
                        if(cur[i] >= 0){
                                j = get_id(cur);
                                if(!used[j]){
                                        s.insert({sum - a[i][cur[i] + 1] + a[i][cur[i]], j});
                                        used[j] = true;
                                }
                        }
                        cur[i]++;
                }
        }
}