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
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    int gcd=0;
    for(int i = 1 ;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        if(x)
        gcd=__gcd(abs(x),gcd);
        if(y)
        gcd=__gcd(abs(y),gcd);
    }
    while(true){ 
        int even=0;
        for(int i = 1;i<=n;i++){
            p[i].x/=gcd;
            p[i].y/=gcd;
            if(p[i].x%2==0)even=1;
            if(p[i].y%2==0)even=1;
        }
        if(!even){
            gcd=0;
            for(int i = 1;i<=n;i++){
                p[i].x++;
                p[i].y++;
                if(p[i].x)
                gcd=__gcd(gcd,p[i].x);
                if(p[i].y)
                gcd=__gcd(gcd,p[i].y);
            }
            continue;
        }
        vector<int> v;
        for(int i =1;i<=n;i++){
            if((p[i].x+p[i].y)%2==0){
                v.pb(i);
            }
        }
        if(v.empty()){
            for(int i = 1;i<=n;i++){
                if(p[i].x&1){
                    v.pb(i);
                }
            }
            if(v.empty()){
                gcd=0;
                for(int i = 1;i<=n;i++){
                    p[i].y++;
                    if(p[i].x)
                    gcd=__gcd(gcd,p[i].x);
                    if(p[i].y)
                    gcd=__gcd(gcd,p[i].y);
                }
                continue;
            }
            else if(v.size()==n){
                gcd=0;
                for(int i = 1;i<=n;i++){
                    p[i].x++;
                    if(p[i].x)
                    gcd=__gcd(gcd,p[i].x);
                    if(p[i].y)
                    gcd=__gcd(gcd,p[i].y);
                }
                continue;
            }
            else{
                printf("%d\n",v.size());
                for(auto it:v)
                printf("%d ",it);
                printf("\n");
            }
        }
        else if(v.size()==n){
            v.clear();
            for(int i = 1;i<=n;i++){
                if(p[i].x&1)v.pb(i);
            }
            printf("%d\n",v.size());
            for(auto it:v)
            printf("%d ",it);
            printf("\n");
        }
        else{
            printf("%d\n",v.size());
            for(auto it:v)
            printf("%d ",it);
            printf("\n");
        }
        break;
    }
}
/*
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/