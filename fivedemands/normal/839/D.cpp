#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int n;
vector<int>fact[1000001];
int a[200001];
long long tot[200001],cnt[1000001];
long long score[1000001];
bool p[1000001];
long long p2[200001];
long long ans=0;
long long mod(long long m){
    return m%1000000007;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=1000000 ;i++){
        score[i]=i;
    }
    score[1]=0;
    for(int i=1; i<=1000000 ;i++){
        for(int j=i; j<=1000000 ;j+=i){
            fact[j].push_back(i);
            if(j!=i) score[j]-=score[i];
        }
    }
    p2[0]=1;
    for(int i=1; i<=n ;i++){
        p2[i]=mod(p2[i-1]*2);
        cin >> a[i];
        for(int j=0; j<fact[a[i]].size() ;j++){
            cnt[fact[a[i]][j]]++;
        }
    }
    for(int i=2; i<=1000000 ;i++){
        if(cnt[i]==0) continue;
        ans+=score[i]*mod(cnt[i]*p2[cnt[i]-1]);
        ans=mod(ans);
    }
    cout << ans << endl;
}