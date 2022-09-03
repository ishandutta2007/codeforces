#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
double dis(pll p,pll q){
    return sqrt(sqr(p.x-q.x)+sqr(p.y-q.y));
}
pll getdir(pll p,pll q){
    pll pp=mp(q.x-p.x,q.y-p.y);
    LL gcd=__gcd(pp.x,pp.y);
    pp.x/=gcd;
    pp.y/=gcd;
    if(pp.x<0||(pp.x==0&&pp.y<0))pp.x=-pp.x,pp.y=-pp.y;
    return pp;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    pll p[200005];
    vector<pll> v;
    for(int i = 1;i<=n;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        p[i]=mp(x,y);   
        v.pb(p[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    if(v.size()==1){
        printf("0\n");
        return;
    }
    else if(v.size()==2){
        printf("%.12f\n",dis(v[0],v[1]));
        return;
    }
    while(true){
        int a=rand()%v.size();
        int b=rand()%v.size();
        while(a==b){
            b=rand()%v.size();
        }
        pll pp=getdir(v[a],v[b]);
        int tot=0;
        for(int i = 1;i<=n;i++){
            if(p[i]==v[a])tot++;
            else if(getdir(v[a],p[i])==pp)tot++;
        }
        if(tot==n-1){
            pll Max=v[a],Min=v[a];
            int single=0;
            int val;
            vector<pll> tmp;
            for(int i = 1;i<=n;i++){
                if(p[i]==v[a]){
                    tmp.pb(p[i]);
                }
                else if(getdir(v[a],p[i])==pp){
                    Max=max(Max,p[i]);
                    Min=min(Min,p[i]);
                    tmp.pb(p[i]);
                }
                else{
                    if(i==k)
                    single=1;
                    val=i;
                }
            }  
            if(!single){
                double ans=dis(Max,Min)+min(dis(Max,p[k])+dis(Min,p[val]),dis(Min,p[k])+dis(Max,p[val]));
               // printf("%.12f\n",ans);
                sort(tmp.begin(),tmp.end());
                double add=1e9;
                for(int i = 0;i+1<tmp.size();i++){
                    add=min(add,dis(tmp[i],p[val])+dis(tmp[i+1],p[val])-dis(tmp[i],tmp[i+1]));
                    if(tmp[i]==p[k]){
                        ans=min(ans,dis(p[k],Min)+dis(Min,p[val])+dis(p[val],tmp[i+1])+dis(tmp[i+1],Max));
                    }
                    if(tmp[i+1]==p[k]){
                        ans=min(ans,dis(p[k],Max)+dis(Max,p[val])+dis(p[val],tmp[i])+dis(tmp[i],Min));
                    }
                }
                ans=min(ans,dis(Max,Min)+min(dis(Max,p[k]),dis(Min,p[k]))+add);
               // printf("%.12f %.12f %.12f\n",dis(Max,Min),min(dis(Max,p[k]),dis(Min,p[k])),add);
                printf("%.12f\n",ans);
            }
            else{
                double ans=dis(Max,Min)+min(dis(Max,p[k]),dis(Min,p[k]));
                printf("%.12f\n",ans);
            }
            break;
        }
    }
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/