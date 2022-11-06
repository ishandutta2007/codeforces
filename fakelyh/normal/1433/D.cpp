#include<bits/stdc++.h>
using namespace std;
int t,n,a,f[5005];
vector<pair<int,int> >ans;
bool u[5005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a),f[i]=a;
        memset(u,0,sizeof(u));u[1]=1;int z=n-1;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)if(u[i]&&!u[j]&&f[i]!=f[j]){
            ans.push_back(make_pair(i,j));
            // printf("%d %d\n",i,j);
            u[j]=1;z--;
        }
        if(z)puts("NO");
        else{
            puts("YES");
            for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
        }
        ans.clear();
    }
    return 0;
}