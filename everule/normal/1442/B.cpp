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
const int p = 998244353;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a;
    for(auto &x : a) --x;
    vector<int> ainv(n);
    for(int i=0;i<n;i++){
        ainv[a[i]] = i;
    }
    vector<int> b(k);
    cin>>b;
    for(auto &x : b) --x, x = ainv[x];
    ll ans = 1;
    set<int> left;
    vector<bool> needed(n,0);
    for(auto &x : b) needed[x] = 1;
    for(int i=0;i<n;i++){
        left.insert(i);
    }
    auto leftc = [&](set<int>::iterator it){
        if(it == left.begin()) return 0;
        --it;
        if(needed[*it]) return 0;
        return 1;
    };
    auto rightc = [&](set<int>::iterator it){
        ++it;
        if(it == left.end()) return 0;
        if(needed[*it]) return 0;
        return 1;
    };
    auto remleft = [&](std::set<int>::iterator it){
        if(it == left.begin()) return false;
        --it;
        if(needed[*it]) return false;
        left.erase(it);
        return true;
    };
    auto remright = [&](std::set<int>::iterator it){
        ++it;
        if(it == left.end()) return false;
        if(needed[*it]) return false;
        left.erase(it);
        return true;
    };
    for(const auto &x : b){
        auto it = left.find(x);
        int choice = leftc(it) + rightc(it);
        ans*=choice;
        if(choice==0){
            break;
        }
        if(!remleft(it)){
            remright(it);
        }
        needed[x] = 0;
        ans%=p;
    }
    cout<<ans<<"\n";
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