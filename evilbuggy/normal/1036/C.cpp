#include <bits/stdc++.h>

using namespace std;

long long int dp[20][4][2];

long long int getClassy(int ind, int cnt, bool tight, vector<int> &dig){
    if(ind == dig.size())return 1;
    if(cnt == 3){
        return 1;
    }
    if(dp[ind][cnt][tight] != -1)return dp[ind][cnt][tight];
    int ml = tight?dig[ind]:9;
    long long int ret = 0;

    for(int i = 0; i <= ml; i++){
        bool nTight = (dig[ind] == i)?tight:false;
        int add = (i == 0)?0:1;
        ret += getClassy(ind + 1, cnt + add, nTight, dig);
    }
    return dp[ind][cnt][tight] = ret;
}

void getDig(long long int n, vector<int> &dig){
    dig.clear();
    while(n > 0){
        dig.push_back(n%10);
        n /= 10;
    }
    reverse(dig.begin(), dig.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    long long int l,r, ans;
    vector<int> dig;
    while(t--){
        cin>>l>>r;
        memset(dp, -1, sizeof(dp));
        getDig(r, dig);
        long long int ans = getClassy(0, 0, true, dig);
        if(l == 1){
            ans--;
        }else{
            memset(dp, -1, sizeof(dp));
            getDig(l-1, dig);
            ans -= getClassy(0, 0, true, dig);
        }
        cout<<ans<<endl;
    }
}