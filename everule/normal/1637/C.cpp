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
    ll odd = 0;
    ll sum = 0;
    for(int i=1;i<n-1;i++){
        odd += (a[i] % 2 == 1);
        sum += a[i];
    }
    if(n == 3 && a[1] % 2 == 1){
        cout<<"-1\n";
        return;
    }
    if(*max_element(a.begin()+1, a.end()-1) == 1){
        cout<<"-1\n";
        return;
    }
    cout<<(sum+odd)/2<<"\n";
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