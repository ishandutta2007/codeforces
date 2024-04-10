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
    vector<array<int, 5>> r(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>r[i][j];
        }
    }
    auto cmp = [&](int i1,int i2){
        int ans = 0;
        for(int i=0;i<5;i++){
            ans += (r[i1][i] < r[i2][i]);
        }
        return ans >= 3 ? i1 : i2;
    };
    int bst = 0;
    for(int i=1;i<n;i++){
        bst = cmp(i, bst);
    }
    for(int i=0;i<n;i++){
        if(bst != cmp(i, bst)){
            cout<<"-1\n";
            return;
        }
    }
    cout<<bst + 1<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}