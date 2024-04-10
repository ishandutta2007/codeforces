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
#define rank Rank
#define MXN 200005
int main(){ 
    //printf("%d\n",atan2l(2000000000,2000000000)>atan2l(2000000000,1999999999));
   // printf("%d\n",atan2l(2000000000,2000000000)>atan2l(1999999999,2000000000));
    int n;
    scanf("%d",&n);
    pii p[2505];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    LL tot=(LL)n*(n-1)*(n-2)*(n-3)*(n-4)/24;
   // printf("%lld\n",tot);
    for(int i = 0;i<n;i++){
        vector<long double> v;
        for(int j=0;j<n;j++){
            if(i!=j){
                v.pb(atan2l(p[j].y-p[i].y,p[j].x-p[i].x));
            }
        }
        sort(v.begin(),v.end());
     //   for(auto it:v)
     //       cout<<it<<" ";
      //  printf("\n");
        for(int j=0;j<n-1;j++){
            v.pb(v[j]+2*pi);
        }
        for(int j =0;j<n-1;j++){
            LL x=(lower_bound(v.begin(),v.end(),v[j]+pi)-v.begin()-j-1);
            tot-=x*(x-1)*(x-2)/6;
         //   printf("%d %d %d\n",i,j,x);
        }
    }
    printf("%lld\n",tot);
}
/**/