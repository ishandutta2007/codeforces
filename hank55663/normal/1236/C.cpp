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
#define MXN 1500
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v[305];
    
    for(int i = 0;i<n;i++){
        vector<pii> vv;
        for(int j = 0;j<n;j++){
            vv.pb(mp(j^i,j));
        }
        if(i&1)reverse(vv.begin(),vv.end());
        //sort(vv.begin(),vv.end());
        for(int j = 0;j<n;j++){
            v[vv[j].y].pb(i*n+j+1);
        }
    
    }
   /* for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==j)continue;
            int tot=0;
            for(auto it:v[i]){
                for(auto it2:v[j]){
                    if(it>it2)tot++;
                }
            }
            printf("%d %d %d\n",i,j,tot);
        }
    }*/
    for(int i = 0;i<n;i++,printf("\n"))
    for(auto it:v[i]){
        printf("%d ",it);
    }
}