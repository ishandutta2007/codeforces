#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
//#define N 262144
#define ULL unsigned long long
bool cmp(const pair<pll,int> &p,const pair<pll,int> &q){
    if(p.x.x*q.x.y!=q.x.x*p.x.y)
    return p.x.x*q.x.y<q.x.x*p.x.y;
    else
    return p.y<q.y;
}
bool cmp3(const pll &p,const pll &q){
    return p.x*q.y<=q.x*p.y;
}
struct cmp2{
    bool operator()(const pair<pll,pair<pii,int> > &p,const pair<pll,pair<pii,int> > &q){
        return cmp3(q.x,p.x);
    }
};
int main(){
    int n;
    scanf("%d",&n);
    pair<pii,int> p[2005];
    map<int,int> minx,maxx;
    for(int i = 0;i<n;i++){
        int x1,x2,y1;
        scanf("%d %d %d",&x1,&x2,&y1);
        p[i]=mp(mp(x1,x2),y1);
        if(minx.find(y1)==minx.end()){
            minx[y1]=x1;
            maxx[y1]=x2;
        }
        else{
            minx[y1]=min(minx[y1],x1);
            maxx[y1]=max(maxx[y1],x2);
        }
    }
    vector<pair<pll,int> > vv;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(p[i].y>p[j].y){
                vv.pb(mp(mp(p[j].x.x-p[i].x.y,p[i].y-p[j].y),1));
                vv.pb(mp(mp(p[j].x.y-p[i].x.x,p[i].y-p[j].y),-1));
            }
        }
    }

    sort(vv.begin(),vv.end(),cmp);
    vector<int> v,v2;
    for(auto it:minx)v.pb(it.x),v2.pb(it.x);
    reverse(v.begin(),v.end());
    reverse(v2.begin(),v2.end());
    priority_queue<pair<pll,pair<pii,int> > ,vector<pair<pll,pair<pii,int> > >, cmp2 > pq1,pq2;
    for(int i = 0;i<v.size()-1;i++){
   //     printf("%lld %lld %lld\n",minx[v[i]],minx[v[i+1]],v[i]-v[i+1]);
        pq1.push(mp(mp(minx[v[i+1]]-minx[v[i]],v[i]-v[i+1]),mp(mp(v[i],v[i+1]),i)));
        pq2.push(mp(mp(maxx[v2[i+1]]-maxx[v2[i]],v2[i]-v2[i+1]),mp(mp(v2[i],v2[i+1]),i)));
       // printf("%d ")
    }
    int sum=0;
    double ans=1e18;
    if(v.size()==1){
        printf("%d\n",maxx[v[0]]-minx[v[0]]);
        return 0;
    }
    for(auto it:vv){
        while(pq1.size()&&cmp3(pq1.top().x,it.x)){
            auto p=pq1.top().y;
            //  printf("%d %d %d %d\n",pq1.top().x.x,p.y,p.x.x,p.x.y);
             pq1.pop();
             
            if(v[p.y]==p.x.x&&v[p.y+1]==p.x.y){
             //   printf("%d ?\n",p.y);
                swap(v[p.y],v[p.y+1]);
                if(p.y!=0){
                    if(v[p.y-1]>v[p.y])
                    pq1.push(mp(mp(minx[v[p.y]-minx[v[p.y-1]]],v[p.y-1]-v[p.y]),mp(mp(v[p.y-1],v[p.y]),p.y-1)));
                }
                if(p.y+1!=v.size()-1){
                    if(v[p.y+1]>v[p.y+2])
                     pq1.push(mp(mp(minx[v[p.y+2]]-minx[v[p.y+1]],v[p.y+1]-v[p.y+2]),mp(mp(v[p.y+1],v[p.y+2]),p.y+1)));
                }
            }
           
        }
        while(pq2.size()&&cmp3(pq2.top().x,it.x)){
            auto p=pq2.top().y;
           // printf("%d %d %d %d\n",pq2.top().x.x,p.y,p.x.x,p.x.y);
             pq2.pop();
            if(v2[p.y]==p.x.x&&v2[p.y+1]==p.x.y){
              //  printf("%d ?\n",p.y);
                swap(v2[p.y],v2[p.y+1]);
                if(p.y!=0){
                      if(v2[p.y-1]>v2[p.y]){
                        // printf("add %d %d %d %d\n",v2[p.y-1],v2[p.y],maxx[v2[p.y-1]]-maxx[v2[p.y]],v2[p.y-1]-v2[p.y]);
                        pq2.push(mp(mp(maxx[v2[p.y]]-maxx[v2[p.y-1]],v2[p.y-1]-v2[p.y]),mp(mp(v2[p.y-1],v2[p.y]),p.y-1)));
                      }
                }
                if(p.y+1!=v2.size()-1){
                    if(v2[p.y+1]>v2[p.y+2]){
                     //   printf("add %d %d %d %d\n",v2[p.y+1],v2[p.y+2],maxx[v2[p.y+1]]-maxx[v2[p.y+2]],v2[p.y+1]-v2[p.y+2]);
                     pq2.push(mp(mp(maxx[v2[p.y+2]]-maxx[v2[p.y+1]],v2[p.y+1]-v2[p.y+2]),mp(mp(v2[p.y+1],v2[p.y+2]),p.y+1)));
                    }
                }
            }
           
        }
        //printf("%lld %lld %d\n",it.x.x,it.x.y,it.y);
        if(sum==0){
         /*   printf("+ %lld %lld\n",it.x.x,it.x.y);
            for(auto it:v)printf("%d ",it);
            printf("\n");
            for(auto it:v2)printf("%d ",it);
            printf("\n");*/
            ans=min(ans,maxx[v2.back()]+1.0*v2.back()*it.x.x/it.x.y-(minx[v[0]]+1.0*v[0]*it.x.x/it.x.y));
        }
        sum+=it.y;
        if(sum==0){
          //  printf("+ %lld %lld %d %d\n",it.x.x,it.x.y,v2.back(),v[0]);
           /*   printf("+ %lld %lld\n",it.x.x,it.x.y);
            for(auto it:v)printf("%d ",it);
            printf("\n");
            for(auto it:v2)printf("%d ",it);
            printf("\n");*/
            ans=min(ans,maxx[v2.back()]+1.0*v2.back()*it.x.x/it.x.y-(minx[v[0]]+1.0*v[0]*it.x.x/it.x.y));
        }
    }
    printf("%.12lf\n",ans);
}