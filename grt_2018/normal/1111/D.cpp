#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[52],q;
long long factorial[100*1000+1];
long long single_product;
const int MOD=1000*1000*1000+7;

long long fast_power(long long a,int b) {
    long long w=1;
    while(b>0) {
        if(b&1) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}

int dp[1000*100+1];
int ans[52][52];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int n = (int)s.size();
    factorial[0]=1;
    for(int i=0; i<s.size();i++) {
        if(s[i]>='a') cnt[s[i]-'a']++;
        else cnt[s[i]-'A'+26]++;
        factorial[i+1] = (factorial[i]*(i+1))%MOD;
    }
    single_product = (factorial[n/2]*factorial[n/2])%MOD;
    for(int i=0; i<52;i++) {
        if(cnt[i]) {
            single_product = ((long long)single_product * fast_power(factorial[cnt[i]],MOD-2))%MOD;
        }
    }
    dp[0]=1;
    for(int i=0; i<52;i++) {
        if(cnt[i]) {
            for(int j=n/2; j>=cnt[i]; j--) dp[j] = (dp[j] + dp[j-cnt[i]])%MOD;
        }
    }
    //cout<<dp[n/2]<<"\n";
    for(int fc = 0; fc<52;fc++) {
        if(cnt[fc]) {
            ans[fc][fc] = dp[n/2];
            for(int i=cnt[fc]; i<=n/2; i++) dp[i] = (dp[i] - dp[i-cnt[fc]]+MOD)%MOD;
            for(int sc = 0; sc<52;sc++) {
                if(fc!=sc&&cnt[sc]) {
                    for(int i=cnt[sc]; i<=n/2; i++) dp[i] = (dp[i] - dp[i-cnt[sc]]+MOD)%MOD;
                    ans[fc][sc] = dp[n/2];
                    for(int i=n/2; i>=cnt[sc]; i--) dp[i] = (dp[i] + dp[i-cnt[sc]])%MOD;
                }
            }
            for(int i=n/2; i>=cnt[fc]; i--) dp[i] = (dp[i] + dp[i-cnt[fc]])%MOD;
        }
    }
    cin>>q;
    while(q--) {
        char a,b;
        int w,e;
        cin>>w>>e; a=s[w-1]; b=s[e-1];
        if(a>='a') w = a-'a';
        else w = a-'A'+26;
        if(b>='a') e = b-'a';
        else e = b-'A'+26;
        //cout<<w<<" "<<e<<" "<<single_product<<" "<<ans[w][e]<<"\n";
        if(a!=b)
        cout<<((long long)ans[w][e]*2*single_product)%MOD<<"\n";
        else
            cout<<((long long)ans[w][e]*single_product)%MOD<<"\n";
    }
    return 0;
}