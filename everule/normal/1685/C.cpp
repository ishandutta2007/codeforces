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
    string s;
    cin>>s;
    n *= 2;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) p[i] = p[i-1] + (s[i-1] == ')' ? -1 : 1);
    int mn_neg = n, mx_neg = -1;
    for(int i=1;i<n;i++){
        if(p[i] < 0) mn_neg = min(mn_neg, i), mx_neg = max(mx_neg, i);
    }
    if(mn_neg == n){
        cout<<"0\n";
        return;
    }
    //cout+p;
    auto it1 = max_element(p.begin(), p.begin() + mn_neg);
    auto it2 = max_element(p.begin() + mx_neg, p.end());
    auto it3 = min_element(p.begin(), p.end());
    auto it4 = max_element(p.begin(), p.end());
    auto it5 = max_element(p.begin() + mn_neg, p.begin() + mx_neg);
    //cout<<mn_neg<<" "<<mx_neg<<"\n";
    if(*it1 + *it2 >= *it5){
        cout<<"1\n";
        cout<<it1 - p.begin() + 1<<" "<<it2 - p.begin()<<"\n";
        return;
    }
    cout<<"2\n";
    cout<<"1 "<<it4 - p.begin()<<"\n";
    cout<<it4 - p.begin() + 1<<" "<<n<<"\n";
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