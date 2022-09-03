#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[505];
    map<int,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for(auto it:m){
        if(it.y&1){
            printf("-1\n");
            return;
        }
    }
    vector<int> v;
    for(int i = 0;i<n;i++)v.pb(a[i]);
    vector<int> tmp;
    vector<pii> ans;
    vector<int> ans2;
    while(v.size()){
        int x=v.back();
        v.pop_back();
        while(v.back()!=x){
            tmp.pb(v.back());
            v.pop_back();
        }
        v.pop_back();
        int tot=tmp.size()*2+2;
        reverse(tmp.begin(),tmp.end());
        while(tmp.size()){
            ans.pb(mp(v.size(),tmp.back()));
            v.pb(tmp.back());
            tmp.pop_back();
        }
        ans2.pb(tot);
    }
    printf("%d\n",ans.size());
    for(auto it:ans)printf("%d %d\n",it.x,it.y);
    reverse(ans2.begin(),ans2.end());
    printf("%d\n",ans2.size());
    for(auto it:ans2)printf("%d ",it);
    printf("\n");
        
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}