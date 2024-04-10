#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL Min=0,Max=0;
vector<int> v[100005];
vector<int> v1,v2;
int n;
int Size[100005];
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    if(Size[x]&1)Min++,v1.pb(x);
    else v2.pb(x);
    Max+=min(Size[x],n-Size[x]);
}
int need[100005];
int go[100005];
bool cmp(const int &x,const int &y){
    return need[x]>need[y];
}
vector<pii> ans;
set<int> dfs2(int x,int f){
    for(auto &it:v[x]){
        if(it==f){
            swap(v[x].back(),it);
            break;
        }
    }
    if(v[x].back()==f)
    v[x].pop_back();
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    int tot=0;
    for(auto it:v[x]){
        if(need[it])
        pq.push(mp(need[it],it));
        tot+=need[it];
    }
    tot++;
    while(tot>need[x]){
        if(tot==need[x]+2&&pq.size()<=1)break;
        pii p=pq.top();
        pq.pop();
        pii q=pq.top();
        pq.pop();
        p.x--;
        q.x--;
        go[p.y]++;
        go[q.y]++;
        if(p.x)pq.push(p);
        if(q.x)pq.push(q);
        tot-=2;
    }
    set<int> s;
    vector<int> v1;
    if(tot==need[x])
    s.insert(x);
    else{
        v1.pb(x);
        pii p=pq.top();
        pq.pop();
        go[p.y]++;
    }
    for(auto it:v[x]){
        if(it!=f){
            //printf("%d\n",it);
            set<int> s2=dfs2(it,x);
            while(go[it]){
                v1.pb(*s2.begin());
                s2.erase(s2.begin());
                go[it]--;
            }
            if(s2.size()>s.size())swap(s2,s);
            for(auto it:s2)s.insert(it);
        }
    }
    /*printf("x:%d %d\n",x,tot);
    for(auto it:s)printf("%d ",it);
    printf("\n");*/
    for(int i = 0;i<v1.size()/2;i++){
        ans.pb(mp(v1[i],v1[v1.size()/2+i]));
    }
    return s;
}
void solve(){
    LL k;
    scanf("%d %lld",&n,&k);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    if(k<Min||k>Max||(k%2)!=(Min%2)){
        printf("NO\n");
    }
    else{
        printf("YES\n");
      //  dfs(1,0);
        int Max=n,Min=1;
        while(Max>=Min){
            int mid=(Max+Min)/2;
            if(mid%2){
                LL l=0,r=0;
                for(auto it:v1){
                    l+=min(mid,min(Size[it],n-Size[it]));
                }
                r=l;
                //printf("%d %d %d %d\n",l,r,mid,v1.size());
                //getchar();
                for(auto it:v2){
                    int Max=min(Size[it],n-Size[it]);
                    if(Max>=mid+1){
                        r+=mid+1;
                        l+=mid-1;
                    }
                    else{
                        r+=Max;
                        l+=Max;
                    }
                }
                if(k>=l&&k<=r){
                    for(auto it:v1){
                        need[it]=min(mid,min(Size[it],n-Size[it]));
                    }   
                    k-=l;
                    for(auto it:v2){
                        int Max=min(Size[it],n-Size[it]);
                        if(Max>=mid+1){
                            if(k)need[it]=mid+1,k-=2;
                            else need[it]=mid-1;
                        }
                        else{
                            need[it]=Max;
                        }
                    }    
                    break;
                }
                if(k<l)Max=mid;
                else Min=mid;
            }
            else{
                LL l=0,r=0;
                for(auto it:v2){
                    l+=min(mid,min(Size[it],n-Size[it]));
                }
                r=l;
                for(auto it:v1){
                    int Max=min(Size[it],n-Size[it]);
                    if(Max>=mid+1){
                        r+=mid+1;
                        l+=mid-1;
                    }
                    else{
                        r+=Max;
                        l+=Max;
                    }
                }
                if(k>=l&&k<=r){
                    for(auto it:v2){
                        need[it]=min(mid,min(Size[it],n-Size[it]));
                    } 
                    k-=l;
                    for(auto it:v1){
                        int Max=min(Size[it],n-Size[it]);
                        if(Max>=mid+1){
                            if(k)need[it]=mid+1,k-=2;
                            else need[it]=mid-1;
                        }
                        else{
                            need[it]=Max;
                        }
                    } 
                    break;
                }
                 if(k<l)Max=mid;
                else Min=mid;
            }
        }
       // printf("%d %d\n",Max,Min);
        //for(int i = 1;i<=n;i++)printf("%d ",need[i]);
        dfs2(1,0);
        for(auto it:ans){
            printf("%d %d\n",it.x,it.y);
        }
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/