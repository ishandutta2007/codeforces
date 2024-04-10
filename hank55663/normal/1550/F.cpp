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
#define last Last
#define MXN 200005
void solve(){
    int n,q,s,d;
    scanf("%d %d %d %d",&n,&q,&s,&d);
    s--;
    int a[200005];
    int ans[200005];
    int loc[200005];
    fill(ans,ans+n,-1);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    int now=0;
  //  ans[s]=0;
    
    int index=lower_bound(a,a+n,a[s]+d)-a;
    
    if(index!=n)
    pq.push(mp(a[index]-a[s]-d,index));
    
    if(index-1!=s){
        pq.push(mp(a[s]+d-a[index-1],index-1));
    }
    
    index=lower_bound(a,a+n,a[s]-d)-a;
    if(index!=s){
        pq.push(mp(a[index]-a[s]+d,index));
    }
    if(index!=0){
        pq.push(mp(a[s]-d-a[index-1],index-1));
    }
    
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        now=max(now,p.x);
      //  printf("%d %d\n",p.y,p.x);
        if(ans[p.y]!=-1){
            if(loc[p.y]>p.x){
                loc[p.y]=p.x;
                loc[p.y]=p.x;
                if(p.y!=n-1&&ans[p.y+1]==-1){
                    pq.push(mp(a[p.y+1]-a[p.y]+p.x,p.y+1));
                }
                if(p.y!=0&&ans[p.y-1]==-1){
                    pq.push(mp(a[p.y]-a[p.y-1]+p.x,p.y-1));
                }
            }
            continue;
        }
        ans[p.y]=now;
        loc[p.y]=now;
        int index=lower_bound(a,a+n,a[p.y]+d)-a;
    
        if(index!=n&&(ans[index]==-1||loc[index]>a[index]-a[p.y]-d))
            pq.push(mp(a[index]-a[p.y]-d,index));
    
        if(ans[index-1]==-1||loc[index-1]>a[p.y]+d-a[index-1]){
            pq.push(mp(a[p.y]+d-a[index-1],index-1));
        }
    
        index=lower_bound(a,a+n,a[p.y]-d)-a;
       // printf("!%d\n",index);
        if(ans[index]==-1||loc[index]>a[index]-a[p.y]+d){
            pq.push(mp(a[index]-a[p.y]+d,index));
        }
    
        if(index!=0&&(ans[index-1]==-1||loc[index-1]>a[p.y]-d-a[index-1])){
          //  printf("?? %d %d\n",index,a[p.y]-d-a[index-1]);
            pq.push(mp(a[p.y]-d-a[index-1],index-1));
        }
    
        if(p.y!=n-1&&(ans[p.y+1]==-1||loc[p.y+1]>a[p.y+1]-a[p.y]+p.x)){
            pq.push(mp(a[p.y+1]-a[p.y]+p.x,p.y+1));
        }
        if(p.y!=0&&(ans[p.y-1]==-1||loc[p.y-1]>a[p.y]-a[p.y-1]+p.x)){
            pq.push(mp(a[p.y]-a[p.y-1]+p.x,p.y-1));
        }
    }
    while(q--){
        int i,k;
        scanf("%d %d",&i,&k);
        i--;
        if(i==s){
            printf("YES\n");
        }
       else if(ans[i]<=k)printf("YES\n");
        else printf("No\n");
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}