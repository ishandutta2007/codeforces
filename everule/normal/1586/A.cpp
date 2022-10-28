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
    vector<int> a(n);
    cin>>a;
    int sum = accumulate(a.begin(), a.end(), 0);
    for(int i=2;i<sum;i++) if(sum % i == 0){
        cout<<n<<"\n";
        for(int i=0;i<n;i++) cout<<i+1<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i] % 2 == 1){
            cout<<n-1<<"\n";
            for(int j=0;j<n;j++) if(i != j) cout<<j+1<<" ";
            cout<<"\n";
            return;
        }
    }
    assert(false);
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