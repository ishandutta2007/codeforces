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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
int pre[200005][2];
int preh[200005];
LL mod[2];
LL Hash[2][200005];
LL base[2][200005];
pll getHash(int l,int r){
    return mp(((Hash[0][r]-Hash[0][l-1]*base[0][r-l+1])%mod[0]+mod[0])%mod[0],
              ((Hash[1][r]-Hash[1][l-1]*base[1][r-l+1])%mod[1]+mod[1])%mod[1]);
}
vector<pii> q[200005];
vector<pair<pll,int> > ans[200005];
int main(){
    srand(time(NULL));
    for(int t=0;t<2;t++){
        mod[t]=rand()%1000000000+1000000000;
        while(true){
            int ok=1;
            for(int i = 2;i*i<=mod[t];i++){
                if(mod[t]%i==0){
                    ok=0;
                }
            }
            if(ok)break;
            mod[t]++;
        }
        base[t][0]=1;
        for(int i = 1;i<200005;i++){
            base[t][i]=base[t][i-1]*2%mod[t];
        }
    }
    int n;
    scanf("%d",&n);
    char c[200005];
    c[0]=0;
    scanf("%s",c+1);
    int qq;
    scanf("%d",&qq);
    for(int i = 0;i<qq;i++){
        int a,b,len;
        scanf("%d %d %d",&a,&b,&len);
        q[b+len-1].pb(mp(b,i));
        q[a+len-1].pb(mp(a,i));
    }
    vector<pii> v;
    for(int i=1;i<=n;i++){
        if(c[i]=='1'&&!v.empty()&&v.back().y==1){
            v.pop_back();
        }
        else{
            //Hash[0][v.size()]=Has
            v.pb(mp(i,c[i]-'0'));
            Hash[0][v.size()]=(Hash[0][v.size()-1]*2+c[i]-'0')%mod[0];
            Hash[1][v.size()]=(Hash[1][v.size()-1]*2+c[i]-'0')%mod[1];
           // printf("%d\n",v.size());
        }
        for(auto it:q[i]){
            int l=lower_bound(v.begin(),v.end(),mp(it.x,0))-v.begin()+1;
            int r=v.size();
            //printf("?%d %d %d %d %d %d\n",i,it.x,l,r,v[l-1].x,it.y);
            if(v.empty()||l-1==r){
                if((i-it.x+1)%2){
                    ans[it.y].pb(mp(mp(1,1),1));
                }
                else{
                    ans[it.y].pb(mp(mp(0,0),0));
                }
            }
            else if((v[l-1].x-it.x)%2){
                pll p=getHash(l,r);
                int add;
                if(v[l-1].y==0){
                p.x+=base[0][r-l+1];
                p.y+=base[1][r-l+1];
                p.x%=mod[0];
                p.y%=mod[1];
                add=1;
                }
                else{
                    p.x-=base[0][r-l];
                    p.y-=base[1][r-l];
                    p.x=(p.x+mod[0])%mod[0];
                    p.y=(p.y+mod[1])%mod[1];
                    add=-1;
                }
                ans[it.y].pb(mp(p,r-l+1+add));
            }
            else{
                ans[it.y].pb(mp(getHash(l,r),r-l+1));
            }
        }
    }
    for(int i = 0;i<qq;i++){
        //printf("%d %d %d\n%d %d %d\n",ans[i][0].x.x,ans[i][0].x.y,ans[i][0].y,ans[i][1].x.x,ans[i][1].x.y,ans[i][1].y);
        if(ans[i][0]==ans[i][1])printf("YES\n");
        else printf("NO\n");
    }
}