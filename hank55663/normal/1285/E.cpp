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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
int s[400005];
void add(int x,int k){
   // printf("%d %d\n",x,k);
    for(int i = x;i<400005;i+=i&-i){
        s[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
int a[400005];
int val[400005];
int main(){
    int t;
    scanf("%d",&t);
    pii p[200005];
    while(t--){
        int n;
        scanf("%d",&n);
        map<int,int> m;
        vector<pii> v1;
        set<int> v2;
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
          /*  if(x==y){
                v2.insert(mp(x,y));
            }
            else{v1.pb(mp(x,y))};*/
            m[x];
            m[y];
        }
        int index=0;
        for(auto &it:m){
            it.y=++index;
        }
        int sub=1;
        for(int i = 0;i<n;i++){
            p[i].x=m[p[i].x];
            p[i].y=m[p[i].y];
            if(p[i].x==p[i].y){
                if(v2.find(p[i].x)!=v2.end())sub=0;
                v2.insert(p[i].x);
            }
            else{
                v1.pb(mp(p[i].x,p[i].y));
            }
        }
        for(auto it:v1)a[it.x]++,a[it.y]--;
        int ans=0;
        for(int i = 1;i<=index;i++){
            val[i]=val[i-1]+a[i];
        }
        for(int i = 0;i<=index;i++){
            if(val[i]==0&&val[i+1]!=0){
                ans++;
            }
            if(val[i]==1&&val[i+1]>1){
                add(i,1);
            }
            if(val[i+1]==1&&val[i]==0){
                add(i+1,-1);
            }
        }
        
        vector<int> v3;
       // printf("!\n");
        for(auto it:v2){
            if(val[it-1]==0&&val[it]==0)ans++;
            if(val[it-1]==0&&val[it]==1)add(it,1);
            if(val[it-1]==1&&val[it]==0)add(it-1,1);
            if(val[it-1]==1&&val[it]==1)v3.pb(it);
        }
        int res=ans-sub;
      //  int res=ans-1;
        for(auto it:v1){
            int x=query(it.y-1)-query(it.x-1);
            if(val[it.y]==1&&val[it.y-1]==1)x++;
            x+=lower_bound(v3.begin(),v3.end(),it.y)-upper_bound(v3.begin(),v3.end(),it.x);
           // printf("%d ",ans+x);
            res=max(res,ans+x);
        }
        printf("%d\n",res);
        for(auto it:v2){
           // if(val[it-1]==0&&val[it]==0)ans++;
            if(val[it-1]==0&&val[it]==1)add(it,-1);
            if(val[it-1]==1&&val[it]==0)add(it-1,-1);
            //if(val[it-1]==1&&val[it]==1)v3.pb(it);
        }
        for(int i = 0;i<=index;i++){
           // if(val[i]==0&&val[i+1]!=0){
          //      ans++;
           // }
            if(val[i]==1&&val[i+1]>1){
                add(i,-1);
            }
            if(val[i+1]==1&&val[i]==0){
                add(i+1,1);
            }
        }
        fill(val,val+index+5,0);
        fill(a,a+index+5,0);
    }
}