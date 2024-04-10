#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=5e5+3;
typedef long long ll;
typedef pair<int,int> pi;
vector <pi> h[maxn];
vector <int> ans,vc;
int n,m,_,cnt;
bool vis[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=3*n;i++) h[i].clear(),vis[i]=0; cnt=0;
        for (int i=1;i<=m;i++){
            int u,v;scanf("%d%d",&u,&v);
            h[u].pb((pi){v,i});
            h[v].pb((pi){u,i});
        }
        ans.clear(); vc.clear();
        for (int i=1;i<=3*n;i++){
            bool flag=0;
            for (auto e:h[i]){
                int v=e.F;
                if (vis[v]){
                    flag=1; vis[v]=0;
                    ans.pb(e.S);
                    break;
                }
            }
            if (!flag) vis[i]=1,cnt++; else cnt--;
        }
        if (cnt>=n){
            cnt=n; puts("IndSet");
            for (int i=1;i<=3*n;i++) if (vis[i]&&cnt>0) {printf("%d ",i);cnt--;}
        } else {
            puts("Matching"); assert(ans.size()>=n);
            for (int i=0;i<n;i++) printf("%d ",ans[i]);
        }
        puts("");
    }
    return 0;
}