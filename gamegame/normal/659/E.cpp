#include<iostream>
using namespace std;
int par[100001];
int find(int x){
    if(par[x]!=x) par[x]=find(par[x]);
    return par[x];
}
void addlink(int x,int y){
    par[find(x)]=find(y);
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int a[m+1],b[m+1],cnt1[n+1],cnt2[n+1];
    for(int i=1; i<=n ;i++){
        par[i]=i;cnt1[i]=0;cnt2[i]=0;
    }
    for(int i=1; i<=m ;i++){
        cin >> a[i] >> b[i];
        addlink(a[i],b[i]);
    }
    for(int i=1; i<=n ;i++){
        cnt1[find(i)]++;
    }
    for(int i=1; i<=m ;i++){
        cnt2[find(a[i])]++;
    }
    int ans=0;
    for(int i=1; i<=n ;i++){
        if(cnt1[i]==cnt2[i]+1){
            ans++;
        }
    }
    cout << ans << endl;
}