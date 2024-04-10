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
    vector<string> s(n);
    vector<vector<array<int,2>>> pos(n, vector<array<int,2>>(52, {-1,-1}));
    cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size();j++){
            char c = s[i][j];
            int val = 0;
            if('A' <= c && c <= 'Z') val = c - 'A';
            else val = c - 'a' + 26;
            if(pos[i][val][0] == -1){
                pos[i][val][0] = j;
            }
            else{
                pos[i][val][1] = j;
            }
        }
    }
    vector<int> chk(52, 1);
    for(int i=0;i<52;i++){
        for(int j=0;j<n;j++){
            if(pos[j][i][0] == -1) chk[i] = 0;
        }
    }
    vector<vector<int>> dp(52, vector<int>(1<<n, -1));
    vector<vector<array<int,2>>> par(52, vector<array<int, 2>>(1<<n, {-1, -1}));
    function<int(int,int)> solve = [&](int x, int y){
        if(dp[x][y] != -1) return dp[x][y];
        if(chk[x] == 0) return dp[x][y] = 0;
        dp[x][y] = 1;
        for(int i=0;i<n;i++){
            if((y & (1<<i))){
                if(solve(x, y^(1<<i)) <= dp[x][y]) continue;
                dp[x][y] = dp[x][y^(1<<i)];
                par[x][y] = par[x][y^(1<<i)];
            }
        }
        for(int x2=0;x2<52;x2++){
            if(x2 == x && y != (1<<n) - 1) continue;
            if(!chk[x2]) continue;
            bool poss = 1;
            int y2 = 0;
            for(int i=0;i<n;i++){
                if(pos[i][x2][0] > pos[i][x][(y>>i)&1]) poss = 0;
                else if(pos[i][x2][1] < pos[i][x][(y>>i)&1]) y2 ^= (1<<i);
            }
            if(poss && solve(x2,y2) >= dp[x][y]){ 
                dp[x][y] = dp[x2][y2] + 1;
                par[x][y] = {x2,y2};
            }
        }
        return dp[x][y];
    };
    ll bst = 0, bstx = -1, bsty = -1;
    for(int x=0;x<52;x++){
        for(int y=0;y<(1<<n);y++){
            if(bst < solve(x,y)){
                bstx = x;
                bsty = y;
                bst = solve(x,y);
            }
        }
    }
    int len = bst;
    string ans;
    if(bstx == -1){
        cout<<"0\n\n";
        return;
    }
    do{
        if(bstx < 26){
            ans.push_back(bstx + 'A');
        }
        else{
            ans.push_back(bstx + 'a' - 26);
        }
        int nbstx = par[bstx][bsty][0];
        int nbsty = par[bstx][bsty][1];
        bstx = nbstx;
        bsty = nbsty;
    }while(bstx != -1);
    reverse(ans.begin(), ans.end());
    assert(ans.size() == len);
    cout<<len<<"\n"<<ans<<"\n";
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