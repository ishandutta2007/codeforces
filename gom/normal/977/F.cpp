#include<bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int n,par[N],mx,arr,ans[N],t;
unordered_map<int,int>dp;
unordered_map<int,int>dppar;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    dp.reserve(10000000);
    dppar.reserve(10000000);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int k=dp[a-1];
        par[i]=dppar[a-1];
        if(dp[a]<k+1){
            dp[a]=k+1;
            dppar[a]=i;
            if(mx<k+1){
                mx=k+1;
                arr=i;
            }
        }
    }
    int c=arr;
    while(c){
        ans[t++]=c;
        c=par[c];
    }
    cout<<mx<<'\n';
    for(int i=mx-1;i>=0;i--)
        cout<<ans[i]<<' ';
    return 0;
}