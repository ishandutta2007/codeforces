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
vector<int> v[300005];
LL f[600005],Size[600005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[300005];
    scanf("%s",c+1);
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        while(x--){
            int y;
            scanf("%d",&y);
            v[y].pb(i);
        }
    }
    for(int i = 0;i<2*k;i++){
        f[i]=i;
        if(i>=k)Size[i]=1;
        else Size[i]=0;
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        if(c[i]=='0'){
            if(v[i].size()==1){
                int x=Find(v[i][0]);
                int y=Find(v[i][0]+k);
                if(Size[x]<Size[y])ans=ans-Size[x]+Size[y];
               // printf("%d %d %d %d?\n",Size[x],Size[y],x,y);
                Size[x]+=1e9;
            }
            else{
                assert(v[i].size()==2);
                int a=Find(v[i][0]);
                int aa=Find(v[i][0]+k);
                int b=Find(v[i][1]);
                int bb=Find(v[i][1]+k);
                if(b!=aa){
                    ans-=min(Size[a],Size[aa]);
                    ans-=min(Size[b],Size[bb]);
                    f[b]=aa;
                    Size[aa]+=Size[b];
                    f[a]=bb;
                    Size[bb]+=Size[a];
                    ans+=min(Size[aa],Size[bb]);
                }
            }
        }
        else{
            if(v[i].size()==1){
                int x=Find(v[i][0]+k);
                int y=Find(v[i][0]);
                if(Size[x]<Size[y])ans=ans-Size[x]+Size[y];
                Size[x]+=1e9;
            }
            else{
                if(!v[i].empty()){
                 //   printf("%d\n",v[i].size());
                    assert(v[i].size()==2);
                    int a=Find(v[i][0]);
                    int aa=Find(v[i][0]+k);
                    int b=Find(v[i][1]+k);
                    int bb=Find(v[i][1]);
                    if(b!=aa){
                        ans-=min(Size[a],Size[aa]);
                        ans-=min(Size[b],Size[bb]);
                        f[b]=aa;
                        Size[aa]+=Size[b];
                        f[a]=bb;
                        Size[bb]+=Size[a];
                        ans+=min(Size[aa],Size[bb]);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}