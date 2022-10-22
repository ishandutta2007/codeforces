#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int MAXN = 2*1000*100+10;
const int MOD = 998244353;
int n,k;
int a[MAXN];
long long dp[MAXN][2];
long long ans=1;
vector<vector<int> >V;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    vector<int>tmp;
    for(int i=0; i<n;i+=2) {
        if(i!=0&&a[i-2]==a[i]&&a[i]!=-1) {
            cout<<"0";
            return 0;
        }
        if(i+2<n&&a[i+2]==-1) {
            tmp.push_back(a[i]);
        }
        else if(a[i]==-1) {
            tmp.push_back(a[i]);
            if(i+2<n) tmp.push_back(a[i+2]);
            V.push_back(tmp);
            tmp.clear();
        }
    }
    tmp.clear();
    for(int i=1; i<n; i+=2) {
        if(i!=1&&a[i-2]==a[i]&&a[i]!=-1) {
            cout<<"0";
            return 0;
        }
        if(i+2<n&&a[i+2]==-1) {
            tmp.push_back(a[i]);
        }
        else if(a[i]==-1) {
            tmp.push_back(a[i]);
            if(i+2<n) tmp.push_back(a[i+2]);
            V.push_back(tmp);
            tmp.clear();
        }
    }
    for(auto vi:V) {
        //for(auto it:vi) cout<<it<<" ";
        //cout<<"\n";
        int mn = k;
        if(vi.back()==-1) mn++;
        if(vi[0]==-1) {
            if(vi.back()==-1) {
                dp[0][1]=0;
                dp[0][0]=k;
            }
            else {
                dp[0][1]=1;
                dp[0][0]=k-1;
            }
        }
        else if(vi[0]==vi.back()) {
            dp[0][1] = 1;
            dp[0][0] = 0;
        }
        else {
            dp[0][1] = 0;
            dp[0][0] = 1;
        }
        for(int i=1; i<vi.size();i++) {
            dp[i][0] = (dp[i-1][0]*(mn-2) + dp[i-1][1]*(mn-1))%MOD;
            if(vi.back()==-1) dp[i][1]=0;
            else dp[i][1] = dp[i-1][0];
        }
        if(vi.back()==-1) ans=(ans*dp[vi.size()-1][0])%MOD;
        else ans=(ans*dp[vi.size()-1][1])%MOD;
        //cout<<ans<<"\n";
    }
    cout<<ans;
}