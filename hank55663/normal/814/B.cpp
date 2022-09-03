#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define rank Rank
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    int a[1005],b[1005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)
        scanf("%d",&b[i]);
    int ans[1005];
    int vis[1005];
    MEM(vis);
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            ans[i]=a[i];
            vis[a[i]]=1;
        }
        else{
            v.pb(i);
        }
    }
    if(v.size()==2){
        if(!vis[a[v[0]]]&&!vis[b[v[1]]]&&a[v[0]]!=b[v[1]]){
            ans[v[0]]=a[v[0]];
            ans[v[1]]=b[v[1]];
        }
        else{
            ans[v[0]]=b[v[0]];
            ans[v[1]]=a[v[1]];
        }
    }
    else{
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                ans[v[0]]=i;
                break;
            }
        }
    }
    for(int i =0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}