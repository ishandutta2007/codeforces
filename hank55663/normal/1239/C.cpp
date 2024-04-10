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
#define MXN 1500
#define hash Hash
int mod=1e9+7;
int main(){
    int n,P;
    scanf("%d %d",&n,&P);
    LL t[100005];
    pii p[100005];
    for(int i=0;i<n;i++){
        scanf("%lld",&t[i]);
        p[i]=mp(t[i],i);
    }
    sort(p,p+n);
    set<int> s,s1;
    s.insert(1e9);
    queue<int> q;
    q.push(p[0].y);
    s.insert(p[0].y);
    LL now=p[0].x;
    LL ans[100005];
    int nowt=1;
    while(!q.empty()){
        int x=q.front();
       // printf("%d %d\n",x,q.size());
        q.pop();
       // printf("%d %d %d\n",x,q.size(),now);
        now+=P;
     //   printf("%d %d %d %d\n",x,q.size(),now,p[nowt].x);
        ans[x]=now;
        //printf("%d %d %d %d\n",nowt,n,p[nowt].x,now);
        //getchar();
        while(nowt<n&&p[nowt].x<=now){
            //printf("?\n");
            if(p[nowt].y<*s.begin()){
                q.push(p[nowt].y);
             //   printf("push %d\n",p[nowt].y);
                s.insert(p[nowt].y);
            }
            else{
                s1.insert(p[nowt].y);
            }
            nowt++;
        }
        s.erase(x);
      //  printf("?%d %d\n",*s1.begin(),s.size());
       // for(auto it:s)printf("%d ",it);
        //printf("\n");
        if(s1.size()&&*s1.begin()<*s.begin()){
            s.insert(*s1.begin());
            q.push(*s1.begin());
            s1.erase(s1.begin());
        }
      //  for(auto it:s)printf("%d ",it);
      //  printf("\n");
        if(q.empty()&&nowt!=n){
            q.push(p[nowt].y);
            s.insert(p[nowt].y);
            now=p[nowt].x;
            nowt++;
        }
    }
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
}