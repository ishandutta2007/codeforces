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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> seq(n, vector<int>(m));
    cin>>seq;
    for(int s=0;s<n+m-1;s++){
        //bool flag = 0;
        int xr = 0;
        for(int i=0;i<n;i++){
            int j = s - i;
            if(j<0 || j>=m) continue;
            xr^=seq[i][j];
            //flag |= (seq[i][j] != 0);
        }
        if(xr){
            cout<<"Ashish\n";
            return;
        }
    }
    cout<<"Jeel\n";
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