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
    int n;
    cin>>n;
    int k = 0;
    while(2 * (n - k) - 1 > k){
        ++k;
    }
    vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    int hk = (k + 1) / 2;
    reverse(p.begin(), p.begin() + hk);
    reverse(p.begin() + hk, p.end() - (k % 2 == 0));
    /*
    vector<array<int, 2>> queens;
    for(int i=0;i<k;i++){
        queens.push_back(array<int, 2>({i, p[i]}));
    }
    auto check_cell = [&](array<int, 2> queen, array<int, 2> cell){
        if(queen[0] == cell[0] || queen[1] == cell[1]) return true;
        if(queen[0] - cell[0] == queen[1] - cell[1]) return true;
        return false;
    };
    auto check = [&](vector<array<int, 2>> queens){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool curr = 0;
                for(auto queen : queens) curr |= check_cell(queen, array<int, 2>({i, j}));
                if(curr == 0) return false;
            }
        }
        return true;
    };
    assert(check(queens));
    */
    cout<<k<<"\n";
    for(int i=0;i<k;i++){
        cout<<i+1<<" "<<p[i] + 1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}