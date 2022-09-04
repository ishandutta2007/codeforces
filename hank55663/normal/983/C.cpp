#include<bits/stdc++.h>
#include <unistd.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int dp[2005][1000][10];
int trans[10000];
int rev[10000];
int get_num(vector<int> v){
    int sum=0;
    for(auto it:v)
    {
        sum*=10;
        sum+=it;
    }
    return trans[sum];
}
int main(){
    int index=0;
    for(int i=0;i<10000;i++){
        int k=i;
        vector<int> v;
        while(k){
            v.pb(k%10);
            k/=10;
        }
        reverse(v.begin(),v.end());
        int ok=1;
        for(int j=1;j<v.size();j++)
        if(v[j]<v[j-1])
        ok=0;
        if(ok){
            trans[i]=index;
            rev[index++]=i;
        }
        else{
            sort(v.begin(),v.end());
            int sum=0;
            for(int i=0;i<v.size();i++){
                sum*=10;
                sum+=v[i];
            }
            trans[i]=trans[sum];
        }
    }
    int n;
    scanf("%d",&n);
    pii p[2005];
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
    }
    MEMS(dp);
    queue<pair<pii,int> > q;
    q.push(mp(mp(1,0),0));
    dp[1][0][0]=0;
    for(int i=0;i<=40000;i++){
        queue<pair<pii,int> > q2;
        while(!q.empty()){
           // printf("!\n");
            pair<pii,int> pp =q.front();
            int num=rev[pp.x.y];
          //  printf("%d\n",num);
            vector<int> v;
            while(num){
                v.pb(num%10);
                num/=10;
            }
        //    printf("%d ",pp.x.x);
            //for(auto it:v)
          //  printf("%d",it);
            //printf("%d \n",pp.y);
            if(pp.x.x==n+1&&pp.x.y==0)
            {
                printf("%d\n",i+n*2-1);
                return 0;
            }
            //printf("XD\n");
            q.pop();
           // sleep(1);
            if(pp.y<9){
                pp.y++;
                {
                    vector<int> vv;
                    for(auto it:v)
                    if(it!=pp.y)
                    vv.pb(it);
                    int index=pp.x.x;
                    while(index!=n+1&&p[index].x==pp.y&&vv.size()!=4)
                    vv.pb(p[index++].y);
                    int a=get_num(vv);
                    if(dp[index][a][pp.y]==-1){
                        q2.push(mp(mp(index,a),pp.y));
                        dp[index][a][pp.y] = i;
                    }
                }
                pp.y--;
            }
            if(pp.y>1){
                pp.y--;
                {
                    vector<int> vv;
                    for(auto it:v)
                    if(it!=pp.y)
                    vv.pb(it);
                    int index=pp.x.x;
                    while(index!=n+1&&p[index].x==pp.y&&vv.size()!=4)
                    vv.pb(p[index++].y);
                    int a=get_num(vv);
                    if(dp[index][a][pp.y]==-1){
                        q2.push(mp(mp(index,a),pp.y));
                        dp[index][a][pp.y] = i;
                    }
                }
            }
        }
        swap(q2,q);
    }
    assert(0);
    /*
    for(int i=1;i<=n;i++){
        queue<pii> q2;
        while(!q.empty()){
            pii pp=q.front();
            q.pop();
            int num=rev[pp.x];
            vector<int> v;
            while(num)
            {
                v.pb(num%10);
                num/=10;
            }
            int add=abs(p[i].x-pp.y)+dp[i-1][pp.x][pp.y];
            v.pb(p[i].y);
            if(v.size()!=4){
                int num=get_num(v);
                q2.push(mp(num,p[i].x));
                dp[i][num][p[i].x]=add;
               /* printf("%d ",i);
                for(auto it:v)
                printf("%d ",it);
                printf("%d ",p[i].x);
                printf("%d\n",add);
                assert(num!=0);
            }
            sort(v.begin(),v.end());
            do{
                vector<int> vv;
                for(auto it:v)
                vv.pb(it);
                int sum=0;
                int last=p[i].x;
                while(!vv.empty()){
                    int x=vv.back();
                    vv.pop_back();
                    sum+=abs(last-x);
                    last=x;
                    int num=get_num(vv);
                    if(dp[i][num][x]==-1){
                        q2.push(mp(num,x));
                        dp[i][num][x]=add+sum;
                    }
                    else{
                        dp[i][num][x]=min(dp[i][num][x],add+sum);
                    }
                   /* printf("%d ",i);
                    for(auto it:vv)
                    printf("%d ",it);
                    printf("%d ",last);
                    printf("%d\n",dp[i][num][x]);

                }
            }while(next_permutation(v.begin(),v.end()));
        }
        swap(q,q2);
    }
    int ans=1e9;
    for(int i=1;i<=9;i++){
        if(dp[n][0][i]!=-1)
            ans=min(ans,dp[n][0][i]);
    }
    printf("%d\n",ans+n*2);*/
}
/*
6 4 8 2
4 8 2 2
6 8 2 2
6 4 2 2
6 2 2
6 4 2
8 2 2
XXOXX....X
OO.O....X.
..........
......X...
.....X....
..........
..........
..........
..........
..........
*/