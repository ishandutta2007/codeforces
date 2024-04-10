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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
LL cnt1[80];
LL cnt2[80];
vector<int> v1[4005];
vector<int> v2[4005];
int mod=998244353;
LL C[80][80];
LL inv[80];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void build(){
    for(int i = 0;i<80;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
        inv[i]=f_pow(i,mod-2);
    }
}
int forbid[4005];
vector<pii> Size;
int num[4005][75][75];
int vis[4005][75][75];

int dfs(int x,int f,vector<int> *v){
    int tot=1;
    MEM(num[x]);
    MEM(vis[x]);
    for(auto it:v[x]){
        if(!forbid[it]&&it!=f){
            tot+=dfs(it,x,v);
        }
    }
    Size.pb(mp(tot,x));
    return tot;
}
int find_cen(int x,vector<int> *v){
    Size.clear();
    int tot=dfs(x,0,v);
    sort(Size.begin(),Size.end());
    int cen=lower_bound(Size.begin(),Size.end(),mp(tot/2,10000))->y;
    return cen;
}

void go(int x,vector<int> *v,LL *cnt){
    x=find_cen(x,v);
    queue<pair<int,pii> > q;
    q.push(mp(x,mp(0,0)));
    num[x][0][0]=1;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
       // printf("%d %d %d %d\n",p.x,p.y.x,p.y.y,num[p.x][p.y.x][p.y.y]);
        if(p.y.x==74)break;
        for(auto it:v[p.x]){
            if(forbid[it])continue;
            if(it==x){
                num[it][p.y.x+1][p.y.y+1]+=num[p.x][p.y.x][p.y.y];
                num[it][p.y.x+1][p.y.y+1]%=mod;
                if(!vis[it][p.y.x+1][p.y.y+1]){
                    vis[it][p.y.x+1][p.y.y+1]=1;
                    q.push(mp(it,mp(p.y.x+1,p.y.y+1)));
                }
            }
            else{
                num[it][p.y.x+1][p.y.y]+=num[p.x][p.y.x][p.y.y];
                num[it][p.y.x+1][p.y.y]%=mod;
                if(!vis[it][p.y.x+1][p.y.y]){
                    vis[it][p.y.x+1][p.y.y]=1;
                    q.push(mp(it,mp(p.y.x+1,p.y.y)));
                }
            }
        }
    }
    for(int i = 2;i<=74;i+=2){
        for(int j=1;j<=74;j++){
            
           
            num[x][i][j]=(LL)num[x][i][j]*inv[j]%mod;
           /* if(num[x][i][j]){
                printf("?%d %d %d %d\n",x,i,j,num[x][i][j]);
            }*/
            cnt[i]+=(LL)num[x][i][j]*i;
            /*if(i==4&&num[x][i][j]){
                printf("?%d %d %d\n",x,j,num[x][i][j]);
            }*/
            cnt[i]%=mod;
            for(int k=2;i*k<=74&&j*k<=74;k++){
                num[x][i*k][j*k]-=(LL)num[x][i][j]*j%mod;
                num[x][i*k][j*k]=(num[x][i*k][j*k]%mod+mod)%mod;
                //num[x][i*k][j*k]%=mod;
            }
        }
    }
    cnt[0]++;
    forbid[x]=1;
    for(auto it:v[x]){
        if(!forbid[it]){
            go(it,v,cnt);
        }
    }
}
int main(){
    build();
    int n1,n2,k;
    scanf("%d %d %d",&n1,&n2,&k);
    for(int i = 1;i<n1;i++){
        int x=rand()%i+1,y=i+1;
        scanf("%d %d",&x,&y);
        v1[x].pb(y);
        v1[y].pb(x);
    }
    for(int i = 1;i<n2;i++){
        int x=rand()%i+1,y=i+1;
        scanf("%d %d",&x,&y);
        v2[x].pb(y);
        v2[y].pb(x);
    }
    go(1,v1,cnt1);
    //printf("!\n");
    MEM(forbid);
    go(1,v2,cnt2);
    /*LL cnt=0;
    for(int i = 1;i<=n1;i++){
        MEM(num);
        num[i][0]=1;
        cnt1[0]++;
        for(int t=0;t<k;t++){
            for(int j=1;j<=n1;j++){
              // if(num[j][t])
                for(auto it:v1[j]){
                    num[it][t+1]+=num[j][t];
                    cnt++;
                }
            }
            for(int j=1;j<=n1;j++)num[j][t+1]%=mod;
            cnt1[t+1]+=num[i][t+1];
            cnt1[t+1]%=mod;
        }
    }
    printf("%lld\n",cnt);
    for(int i = 1;i<=n2;i++){
        MEM(num);
        num[i][0]=1;
        cnt2[0]++;
        for(int t=0;t<k;t++){
            for(int j=1;j<=n2;j++){
                for(auto it:v2[j]){
                    num[it][t+1]+=num[j][t];
                }
            }
            for(int j=1;j<=n2;j++)num[j][t+1]%=mod;
            cnt2[t+1]+=num[i][t+1];
            cnt2[t+1]%=mod;
        }
    }*/
    if(k%2!=0){
        printf("0\n");
        return 0;
    }
    LL ans=0;
    for(int i = 74;i>=2;i-=2){
        for(int j=2;i*j<=74;j++){
            cnt1[i*j]+=cnt1[i];
            cnt1[i*j]%=mod;
            cnt2[i*j]+=cnt2[i];
            cnt2[i*j]%=mod;
        }
    }
    for(int i = 0;i<=k;i++){
    //    printf("%d %d %d %d\n",i,cnt1[i],k-i,cnt2[k-i]);
        ans+=cnt1[i]*cnt2[k-i]%mod*C[k][i]%mod;
    }
    printf("%lld\n",ans%mod);
}