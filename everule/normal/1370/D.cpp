#include <iostream>
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
    int n,k;
    cin>>n>>k;
    int k1 = (k+1)/2;
    int k2 = k/2;
    vector<int> seq(n);
    cin>>seq;
    int mn = 0;
    int mx = 1e9 + 7;
    int lim1 = (k1==k2) ? n-1 : n;
    int lim2 = (k1==k2) ? n-1 : n-2;
    while(mn < mx){
        int mid = mn + mx;
        mid>>=1;
        int dp1[lim1+1][2];
        dp1[0][0]=0;
        dp1[0][1]=0;
        for(int i=0;i<lim1;i++){
            if(seq[i] <= mid){
                dp1[i+1][1] = max(dp1[i][0] + 1, dp1[i][1]);
            }
            else{
                dp1[i+1][1] = 0;
            }
            dp1[i+1][0] = max(dp1[i][1], dp1[i][0]);
        }
        int ans1 = max(dp1[lim1][0], dp1[lim1][1]);
        int dp2[lim2 + 1][2];
        dp2[0][0]=0;
        dp2[0][1]=0;
        for(int i=0;i<lim2;i++){
            if(seq[i+1] <= mid){
                dp2[i+1][1] = max(dp2[i][0] + 1, dp2[i][1]);
            }
            else{
                dp2[i+1][1] = 0;
            }
            dp2[i+1][0] = max(dp2[i][1], dp2[i][0]);
        }
        int ans2 = max(dp2[lim2][0], dp2[lim2][1]);
        if(ans1>=k1 || ans2>=k2){
            mx = mid;
        }
        else{
            mn = mid+1;
        }
    }
    cout<<mn<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}