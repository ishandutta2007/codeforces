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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL x=0,y=0;
        char c[200005];
        scanf("%s",c);
        LL Minx=0,Maxx=0,Miny=0,Maxy=0;
        vector<int> xr,yr;
        xr.pb(0);
        yr.pb(0);
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='W')x++;
            if(c[i]=='S')x--;
            if(c[i]=='A')y--;
            if(c[i]=='D')y++;
            Minx=min(Minx,x);
            Miny=min(Miny,y);
            Maxx=max(Maxx,x);
            Maxy=max(Maxy,y);
            xr.pb(x);
            yr.pb(y);
        }
       // LL ax=Maxx-Minxx,ay=Maxy-Miny;
        int l=1e9,r=xr.size()-1;
        int okx=0,oky=0;
        for(int i = 0;i<xr.size();i++){
            if(xr[i]==Maxx){
                l=min(l,i);
       //         r=max(r,i);
            }
        }
        if(l!=0&&xr[l-1]!=Minx){
            int ook=1;
            for(int i =l;i<=r;i++){
                if(xr[i]==Minx){
                    ook=0;
                }
            }
            if(ook)okx=1;
        }
        l=1e9,r=xr.size()-1;
        for(int i = 0;i<xr.size();i++){
            if(xr[i]==Minx){
                l=min(l,i);
                //r=max(r,i);
            }
        }
        if(l!=0&&xr[l-1]!=Maxx){
            int ook=1;
            for(int i =l;i<=r;i++){
                if(xr[i]==Maxx){
                    ook=0;
                }
            }
            if(ook)okx=1;
        }
        l=1e9,r=yr.size()-1;
        for(int i = 0;i<yr.size();i++){
            if(yr[i]==Miny){
                l=min(l,i);
                //r=max(r,i);
            }
        }
        if(l!=0&&yr[l-1]!=Maxy){
            int ook=1;
            for(int i =l;i<=r;i++){
                if(yr[i]==Maxy){
                    ook=0;
                }
            }
            if(ook)oky=1;
        }
       // printf("%d %d %d\n",l,r,oky);
        l=1e9,r=yr.size()-1;
        for(int i = 0;i<yr.size();i++){
            if(yr[i]==Maxy){
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l!=0&&yr[l-1]!=Miny){
            int ook=1;
            for(int i =l;i<=r;i++){
                if(yr[i]==Miny){
                    ook=0;
                }
            }
            if(ook)oky=1;
        }
     /*    for(auto it:xr)
        printf("%d ",it);
        printf("\n");
        for(auto it:yr)
        printf("%d ",it);
        printf("\n");
        printf("%d %d\n",okx,oky);*/
        printf("%lld\n",min((Maxx-Minx+1-okx)*(Maxy-Miny+1),(Maxx-Minx+1)*(Maxy-Miny+1-oky)));
    }
    return 0;
}
/*
1 3 6 10 15
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */