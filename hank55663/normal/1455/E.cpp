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
#define pi acos(-1)
using namespace std;
/*int f[505];
int Find(int x){
    if(f[x]==x)return x;   
    return f[x]=Find(f[x]);
}*/
LL cal(LL x,pll *p){
   // if(x==3)
    //for(int i = 0;i<4;i++)printf("%d %d\n",v[i].x,v[i].y);
    LL xx[4],yy[4];
    for(int i = 0;i<4;i++)xx[i]=p[i].x,yy[i]=p[i].y;
    xx[1]-=x;
    yy[2]-=x;
    xx[3]-=x;
    yy[3]-=x;
    sort(xx,xx+4);
    sort(yy,yy+4);
    LL sum=0;
    for(int i = 0;i<4;i++)sum+=abs(xx[i]-xx[1])+abs(yy[i]-yy[1]);
    return sum;
}
void solve(){
    pll p[4];
    int Maxx=0,Minx=1e9,Maxy=0,Miny=1e9;
    for(int i = 0;i<4;i++){
        int x=rand(),y=rand();
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        Maxx=max(Maxx,x);
        Minx=min(Minx,x);
        Maxy=max(Maxy,y);
        Miny=min(Miny,y);
    }
    sort(p,p+4);
    LL ans=1e10;
    do{
        LL Max=1e9,Min=0;
        while(Max>Min+5){
            LL mid1=(Min+Max)/2,mid2=mid1+1;
            LL a=cal(mid1,p);
            LL b=cal(mid2,p);
            if(a>b)Min=mid1;
            else Max=mid1;
        }
        for(LL i = Min;i<=Max;i++){
            ans=min(ans,cal(i,p));
           // printf("%d\n",i);
        }
    }while(next_permutation(p,p+4));
    printf("%lld\n",ans);

}  
int main(){
    int t=1;
    scanf("%d",&t);
    //int n;
    while(t--){
        solve();
    }
}