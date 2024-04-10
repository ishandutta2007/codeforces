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
#define next Next
using namespace std;
int S[200005];
void add(int x,int k){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
map<int,vector<int> > m;
void solve(){
    int n;
    scanf("%d",&n);
    m.clear();
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        m[-x].pb(i);
    }
    if(m.begin()->y.size()>=3){
        printf("YES\n");
        printf("%d 1 %d\n",m.begin()->y[1]-1,n-m.begin()->y[1]);
        return;
    }
    int l=n,r=1;
    for(auto it:m){
        for(auto it2:it.y){
            add(it2,1);
        }
        if(l<=r){
            int ok=0;
            for(auto it2:it.y){
                if(it2>=l&&it2<=r)ok=1;
                if(it2==l-1&&it2!=it.y[0]){
                    l--;
                    ok=1;
                    break;
                }
                if(it2==r+1&&it2!=it.y.back()){
                    r++;
                    ok=1;
                    break;
                }
            }
            //printf("%d %d %d %d %d\n",it.x,ok,query(r)-query(l-1),l,r);
            if(ok&&query(r)-query(l-1)==r-l+1&&it.y[0]<l&&it.y.back()>r){
                printf("YES\n");
                printf("%d %d %d\n",l-1,r-l+1,n-r);
                for(int i = 1;i<=n;i++){
                    add(i,-query(i)+query(i-1));
                }
                return;
            }
        }
        for(auto it2:it.y)l=min(l,it2),r=max(r,it2);
    }
    printf("NO\n");
      for(int i = 1;i<=n;i++){
                    add(i,-query(i)+query(i-1));
                }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}