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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
void solve(){
    int n ,q;
    scanf("%d %d",&n,&q);
    int a[100005];
    set<pii> s;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!s.empty()&&s.rbegin()->y<=a[i]);
        else s.insert(mp(i,a[i]));
    }
   // printf("%d\n",s.size());
    while(q--){
        int x,b;
        scanf("%d %d",&x,&b);
        auto it=s.lower_bound(mp(x,a[x]));
        if(it!=s.end()&&it->x==x){
            s.erase(mp(x,a[x]));
        }
        a[x]-=b;
        it=s.lower_bound(mp(x,a[x]));
        int ok=1;
        if(it!=s.begin()){
            it=prev(it);
            if(it->y<=a[x]){
                ok=0;
            }
        }
        if(ok){
            s.insert(mp(x,a[x]));
            auto it=next(s.lower_bound(mp(x,a[x])));
            while(it!=s.end()){
                if(it->y>=a[x]){
                    auto it2=next(it);
                    s.erase(it);
                    it=it2;
                }
                else{
                    break;
                }
            }
        }
        printf("%d ",s.size());
    }
    printf("\n");
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}