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
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int follow[300005];
int from[300005];
int head[300005];
int tail[300005];
vector<int> v[300005];
int in[300005];
int instk[300005];
bool solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int p[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i = 0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        follow[x]=y;
        from[y]=x;
    }
    for(int i = 1;i<=n;i++){
        if(from[i]==0){
            int now=i;
            head[i]=i;
            instk[now]=1;
            while(follow[now]){
                
                now=follow[now];
                if(instk[p[now]])p[now]=0;
                instk[now]=1;
                head[now]=i;
            }
            now=i;
            instk[now]=0;
            while(follow[now]){
                now=follow[now];
                   instk[now]=0;
            }
        }
        if(follow[i]==0){
            int now=i;
            tail[i]=i;
            while(from[now]){
                now=from[now];
                tail[now]=i;
            }
        }
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(p[i]==0){
       //     if(head[i]==i)q.push(i);
        }
        else{
            v[tail[p[i]]].pb(head[i]);
           // printf("?%d %d\n",tail[p[i]],head[i]);
            in[head[i]]++;
        }
    }
    for(int i =1;i<=n;i++){
        if(in[i]==0&&head[i]==i)q.push(i);
       // printf("%d %d\n",head[i],tail[i]);
    }
    vector<int> ans;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        ans.pb(x);
        //printf("%d\n",x);
        while(follow[x]){
            x=follow[x];
            ans.pb(x);
        }
        for(auto it:v[x]){
            if(--in[it]==0){
                q.push(it);
            }
        }
    }
    if(ans.size()==n){
        for(auto it:ans)
        printf("%d ",it);
        printf("\n");
    }
    else{
        printf("0\n");
    }
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
}