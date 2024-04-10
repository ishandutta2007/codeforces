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
pair<int,int> operator+(const pair<int,int> &x, const pair<int,int> &y){
    return mp(x.first + y.first, x.second);
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    vector<vector<int>> poss(n+1, vector<int>(n+1));
    for(int i=0;i<n;i++){
        dp[i][i+1] = 0;
        poss[i][i+1] |= (1<<(s[i]-'a'));
    }
    for(int len = 2;len<=n;len++){
        for(int i=0,j=len;j<=n;i++,j++){
            dp[i][j] = 1e9;
            char c = s[i];
            bool flag = 1;
            for(int k=i+1;k<j;k++){
                flag&=(c==s[k]);
                if(dp[i][j] > dp[i][k] + dp[k][j] + ((poss[i][k]&poss[k][j])==0)){
                    dp[i][j] = dp[i][k] + dp[k][j] + ((poss[i][k]&poss[k][j])==0);
                    if(poss[i][k]&poss[k][j]){
                        poss[i][j] = poss[i][k]&poss[k][j];
                    }
                    else{
                        poss[i][j] = poss[i][k]|poss[k][j];
                    }
                }
                if(dp[i][j]== dp[i][k] + dp[k][j] + ((poss[i][k]&poss[k][j])==0)){
                    if(poss[i][k]&poss[k][j]){
                        poss[i][j] |= poss[i][k]&poss[k][j];
                    }
                    else{
                        poss[i][j] |= poss[i][k]|poss[k][j];
                    }
                }
            }
            if(flag) dp[i][j]==0;
        }
    }
    cout<<dp[0][n]+1<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}