#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    //n = rand() % 7 + 1;
    vector<int> a(n);
    cin>>a;
    //for(auto &c : a) c = min(n, rand() % 6 + 1);
    vector<vector<int>> pos(n);
    for(int i=0;i<n;i++) pos[--a[i]].push_back(i);
    vector<array<int, 2>> itl;
    for(int i=0;i<n;i++){
        if(pos[i].size() > 1){
            itl.push_back({pos[i].front(), pos[i].back()});
        }
    }
    sort(itl.begin(), itl.end(), [&](array<int, 2> x, array<int, 2> y){
        return (x[0] < y[0]) + (x[0] == y[0]) * (x[1] > y[1]);
    });
    vector<array<int, 2>> c;
    int ans = 0;
    for(int i=0;i<itl.size();i++){
        if(!c.empty() && c.back()[1] < itl[i][0]){
            //for(auto &x : c) cout<<x[0]<<" "<<x[1]<<"\n";
            //cout<<"\n";
            ans += c.back()[1] - c.front()[0] - c.size();
            c.clear();
            c.push_back(itl[i]);
        }
        while(c.size() > 1 && c.end()[-2][1] > itl[i][0] && c.end()[-1][1] < itl[i][1]){
            c.pop_back();
        }
        if(c.empty() || c.back()[1] < itl[i][1]){
            c.push_back(itl[i]);
        }
    }
    if(!c.empty()) ans += c.back()[1] - c.front()[0] - c.size();
    cout<<ans<<"\n"; 
    /*
    vector<int> vis(1<<n);
    function<void(int)> dfs = [&](int m){
        if(vis[m]) return;
        vis[m] = 1;
        for(int i=0;i<n;i++){
            if(m & (1<<i)) continue;
            for(int j=0;j<i;j++){
                if(m & (1<<j)) continue;
                for(int k=i+1;k<n;k++){
                    if(m & (1<<k)) continue;
                    if(a[j] == a[k]){
                        dfs(m | (1<<i));
                    }
                }
            }
        }
    };
    dfs(0);
    int ans2 = 0;
    for(int i=0;i<(1<<n);i++){
        if(vis[i]) ans2 = max(ans2, __builtin_popcount(i));
    }
    if(ans != ans2){
        cout<<n<<"\n";
        cout+a;
        cout<<ans<<" "<<ans2<<"\n";
        exit(0);
    }
    if(rand() % 1000 == 0) cout<<"...\n";*/
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}