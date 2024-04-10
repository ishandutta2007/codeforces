#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int r,d;
    scanf("%d %d",&r,&d);
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i = 0;i<n;i++){
        int x,y,rr;
        scanf("%d %d %d",&x,&y,&rr);
        if(x*x+y*y>=(r-d+rr)*(r-d+rr)){
            if(x*x+y*y<=(r-rr)*(r-rr)&&rr<=d){
                ans++;
                //printf("%d\n",i);
            }
        }
        
    }
    printf("%d\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/