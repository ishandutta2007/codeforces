#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=2e6+15;
map <int,int> f;
vector <int> a;
int T,n,cnt[maxn],ans,m;

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        f.clear(); a.clear();
        m=2e6+10; ans=n;
        while (n--){
            int x;scanf("%d",&x);
            f[x]++;
        }
        for (auto x:f) m=min(m,x.S+1),a.pb(x.S);
        for (int i=2;i<=m;i++){
            bool flag=1;
            for (auto x:a) if (x/(i-1)*i<x) flag=0;
            if (flag){
                int res=0;
                for (auto x:a) res+=(x+i-1)/i;
                ans=min(ans,res);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}