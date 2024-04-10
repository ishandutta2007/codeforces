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
using namespace std;
bool solve(){
    map<int,int> m;
    m[0]=m[1e9+7]=-1;
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i==0)m[x]=0;
        else{
            auto it=m.lower_bound(x);
            auto it2=prev(it);
            if(it->y>it2->y){
                printf("%d ",it->x);
                m[x]=it->y+1;
            }
            else{
                printf("%d ",it2->x);
                m[x]=it2->y+1;
            }
        }
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}