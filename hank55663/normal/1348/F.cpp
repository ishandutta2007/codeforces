#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int n;
    scanf("%d",&n);
    int l[200005],r[200005];
    vector<pii> v[200005];
    //pair<pii,int> p[200005];
    for(int i = 1;i<=n;i++){
        int x,y;
       
        scanf("%d %d",&x,&y);
         l[i]=x;
        r[i]=y;
        //p[i]=mp(mp(x,y),i);
        v[x].pb(mp(y,i));
    }
   // sort(p,p+n);
    vector<int> res;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            pq.push(it);
        }
        res.pb(pq.top().y);
        pq.pop();
    }
    vector<int> res2=res;
    int ok=1;
   // printf("%d ",res[0]);
   while(!pq.empty())pq.pop();
   pq.push(mp(r[res2[0]],0));
    set<int> s;
    s.insert(0);
    for(int i = 1;i<n;i++){
    //    printf("%d ",res[i]);
        while(!pq.empty()&&pq.top().x<i+1){
            s.erase(pq.top().y);
            pq.pop();
        }
        if(s.size()&&*s.rbegin()+1>=l[res2[i]]){
            swap(res2[i],res2[*s.rbegin()]);
            ok=0;
            break;
        }
        pq.push(mp(r[res2[i]],i));
        s.insert(i);
        /*
        if(l[res2[i]]<=i&&r[res2[i-1]]>=i+1){
         //   printf("!! %d %d %d %d\n",l[res2[i]],i,r[res2[i-1]],i+1);
            swap(res2[i],res2[i-1]);
            ok=0;
            //break;
        }*/
    }
 //   printf("\n");
    if(ok){
        printf("YES\n");
        int ans[200005];
        for(int i = 0;i<res.size();i++)ans[res[i]]=i+1;
        for(int i = 1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else{
        printf("NO\n");
        int ans[200005];
        int ans2[200005];
        for(int i = 0;i<res.size();i++)ans[res[i]]=i+1;
        for(int i = 0;i<res2.size();i++)ans2[res2[i]]=i+1;
        for(int i = 1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        for(int i = 1;i<=n;i++){
            printf("%d ",ans2[i]);
        }
        printf("\n");
    }
}