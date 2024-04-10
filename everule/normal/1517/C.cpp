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
    vector<int> p(n);
    cin>>p;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    for(int i=0;i<n;i++){
        int x = p[i];
        ans[i][i] = p[i];
        int cx = i, cy = i;
        while(--x){
            if(cy == 0 || ans[cx][cy-1] != -1){
                cx++;
            }
            else{
                cy--;
            }
            assert(cy >= 0);
            ans[cx][cy] = p[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}