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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
set<int> r,b;
int f[100005];
int cntr[100005],cntb[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    r.clear();
    b.clear();
    scanf("%d",&n);
    int c[100005];
    vector<pii> v;
    for(int i= 1;i<=n;i++){
        int l,r;
        scanf("%d %d %d",&c[i],&l,&r);
        v.pb(mp(l,i));
        v.pb(mp(r+1,-i));
        f[i]=i;
        cntr[i]=cntb[i]=0;
        //if(c[i]==0)cntr[i]++;
        //else cntb[i]++;
    }
    sort(v.begin(),v.end());
    for(auto it:v){
       // printf("? %d %d\n",it.x,it.y);
        if(it.y<0){
            it.y=-it.y;
            int x=Find(it.y);
           // printf("%d\n",x);
            if(c[it.y]==0){
                cntr[x]--;
                if(cntr[x]==0)r.erase(x);
            }
            else{
                cntb[x]--;
                if(cntb[x]==0)b.erase(x);
            }
        }
        else{
            if(c[it.y]==0){
                r.insert(it.y);
                cntr[it.y]++;
            }
            else{
                b.insert(it.y);
                cntb[it.y]++;
            }
            if(r.size()&&b.size()){
                int a=Find(*r.begin());
                for(auto it:r){
               //     printf("%d %d\n",a,it);
                    int x=Find(it);
                    if(x!=a){
                    f[x]=a;
                    cntr[a]+=cntr[x];
                    cntb[a]+=cntb[x];
                    }
                }
                for(auto it:b){
                    
                    int x=Find(it);
                //      printf("%d %d\n",a,it);
                    if(x!=a){
                    f[x]=a;
                    cntr[a]+=cntr[x];
                    cntb[a]+=cntb[x];
                    }
                }
                r.clear();
                b.clear();
                r.insert(a);
                b.insert(a);
            }
        }
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        ans+=f[i]==i;
    }
    printf("%d\n",ans);
}

int main(){
    srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}