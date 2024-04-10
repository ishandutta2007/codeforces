#include <bits/stdc++.h>
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
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<int>> a(k, vector<int>(n, 0));
    cin>>a;
    vector<vector<int>> o(n, vector<int>(k, 0));
    for(int i=0;i<n;i++) iota(o[i].begin(), o[i].end(), 0);
    for(int i=0;i<n;i++){
        sort(o[i].begin(), o[i].end(), [&](int x,int y){
            return a[x][i] > a[y][i];
        });
    }
    vector<bitset<(1<<12)>> char_func(k);
    for(int i=0;i<k;i++){
        for(int m=0;m<(1<<k);m++){
            char_func[i][m] = ((m >> i) & 1);
        }
    }
    vector<int> ans(q);
    for(int _=0;_<q;_++){
        int t;
        cin>>t;
        if(t == 1){
            int x,y;
            cin>>x>>y;
            --x;--y;
            char_func.push_back(char_func[x] | char_func[y]);
        }
        if(t == 2){
            int x,y;
            cin>>x>>y;
            --x;--y;
            char_func.push_back(char_func[x] & char_func[y]);
        }
        if(t == 3){
            int x,y;
            cin>>x>>y;
            --x;--y;
            int c_msk = 0;
            for(auto &i : o[y]){
                c_msk |= (1<<i);
                if(char_func[x][c_msk] == 1){
                    cout<<a[i][y]<<"\n";
                    break;
                }
            }
            assert(char_func[x][c_msk] == 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}