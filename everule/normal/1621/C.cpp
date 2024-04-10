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
    vector<int> p(n, -1);
    auto query = [&](int i){
        cout<<"? "<<i+1<<endl;
        int ans;
        cin>>ans;
        return ans - 1;
    };
    for(int i=0;i<n;i++){
        int prv = query(i);
        while(p[prv] == -1){
            int ch = query(i);
            p[prv] = ch;
            prv = ch;
        }
    }
    cout<<"! ";
    for(int i=0;i<n;i++) cout<<p[i] + 1 << " ";
    cout<<endl;
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