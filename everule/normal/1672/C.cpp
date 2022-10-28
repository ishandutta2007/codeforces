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
    int first = -1, last = -1;
    for(int i=0;i+1<n;i++){
        if(a[i] == a[i+1]){
            first = (first == -1 ? i : first);
            last = i;
        }
    }
    if(first == -1){
        cout<<"0\n";
    }
    else if(last == first){
        cout<<"0\n";
    }
    else if(last - first < 2){
        cout<<"1\n";
    }
    else{
        cout<<last - first - 1<<"\n";
    }
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