#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n,m,a[100005],L[100005],R[100005],x[100005];
int cnt[31][100005],rui[31][100005];
int main(){
    cin>>n>>m;
    rep(i,m){
        cin>>L[i]>>R[i]>>x[i];
        rep(j,30) if(((x[i]>>j)&1)) cnt[j][L[i]]++,cnt[j][R[i]+1]--;
    }
    rep(j,30) for(int i=2;i<=n;i++) cnt[j][i] += cnt[j][i-1];
    rep(j,30) for(int i=1;i<=n;i++) rui[j][i] = rui[j][i-1]+!!cnt[j][i];
    bool ok = 1;
    rep(i,m){
        rep(j,30) if(!((x[i]>>j)&1)) if(rui[j][R[i]] - rui[j][L[i]-1] == R[i]-L[i]+1) ok = 0;
    }
    if(!ok) puts("NO");
    else{
        puts("YES");
        for(int i=1;i<=n;i++){
            int val = 0;
            rep(j,30)val+=!!cnt[j][i] * (1<<j);
            printf("%d ",val);
            puts("");
        }
    }
}