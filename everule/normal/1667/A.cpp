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
    vector<int> a(n);
    cin>>a;
    auto solve_r = [&](vector<int>::reverse_iterator begin, vector<int>::reverse_iterator end){
        ll curr = 0;
        ll ans = 0;
        while(begin != end){
            ll to_add = (curr + *begin) / (*begin);
            ans += to_add;
            curr = to_add * (*begin);
            begin++;
        }
        return ans;
    };
    auto solve_f = [&](vector<int>::iterator begin, vector<int>::iterator end){
        ll curr = 0;
        ll ans = 0;
        while(begin != end){
            ll to_add = (curr + *begin) / (*begin);
            ans += to_add;
            curr = to_add * (*begin);
            begin++;
        }
        return ans;
    };
    ll bst = 1e18;
    for(int zer=0;zer<n;zer++){
        bst = min(bst, solve_f(a.begin() + zer + 1, a.end()) + solve_r(a.rbegin() + n - zer, a.rend()));
    }
    cout<<bst<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}