#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
vector<pair<int,pll>> v[200005];
int Size[200005];
vector<pll> v1,v2;
priority_queue<pair<LL,pii> > pq;
LL sum=0;
void dfs(int x,int f){
    if(v[x].size()==1&&x!=1)
    Size[x]=1;
    else Size[x]=0;

    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            if(it.y.y==1){
                v1.pb(mp(Size[it.x],it.y.x));
                //pq.push(mp((it.y.x+1)/2ll*Size[it.x],mp(Size[it.x],it.y.x)));
            }
            else{
                v2.pb(mp(Size[it.x],it.y.x));
                //pq2.push(mp((it.y.x+1)/2ll*Size[it.x],mp(Size[it.x],it.y.x)));
            }
            Size[x]+=Size[it.x];
            sum+=it.y.x*1ll*Size[it.x];
        }
    }
}
LL cal(LL x,LL s){
    LL tsum=sum;
    LL res=0;
    vector<LL> tmp;
    for(auto it:v1){
        while((it.y+1)/2*it.x){
            tmp.pb((it.y+1)/2*it.x);
            tsum-=(it.y+1)/2*it.x;
            it.y/=2;
            res++;
        }
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    while(pq.size())pq.pop();
    for(auto it:v2){
        pq.push(mp((it.y+1)/2*it.x,it));
    }
    LL ans=1e18;
    while(tmp.size()){
        //printf("?\n");
        while(tsum>s){
         //printf("!\n");
            if(!pq.size())return ans;
            auto p=pq.top();
            if(p.x==0){
                return ans;
            }
            pq.pop();
            res+=2;
            tsum-=p.x;
            p.y.y/=2;
            pq.push(mp((p.y.y+1)/2ll*p.y.x,p.y));
        }
        ans=min(ans,res);
        res--;
        tsum+=tmp.back();
        tmp.pop_back();
    }
    //if(pq.size())
    while(tsum>s){
        //printf("!\n");
        if(!pq.size())return ans;
        auto p=pq.top();
        if(p.x==0){
            return ans;
        }
        pq.pop();
        res+=2;
        tsum-=p.x;
        p.y.y/=2;
        pq.push(mp((p.y.y+1)/2ll*p.y.x,p.y));
    }
    ans=min(ans,res);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        sum=0;
       
        v1.clear();
        v2.clear();
        LL n,s;
        scanf("%lld %lld",&n,&s);
        for(int i= 1;i<=n;i++){
            v[i].clear();
        }
        for(int i = 1;i<n;i++){
            int x=1,y=i+1,w=rand()%1000000+1,c=rand()%2+1;
            scanf("%d %d %d %d",&x,&y,&w,&c);
            v[x].pb(mp(y,mp(w,c)));
            v[y].pb(mp(x,mp(w,c)));
        }
        dfs(1,0);
        printf("%lld\n",cal(1,s));//ans);
    }
}