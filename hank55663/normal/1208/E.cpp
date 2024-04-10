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
LL ans[1000005];
//int pre[1000005];
int main(){
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        vector<pair<int,pii> > v;
        if(w!=x)
        v.pb(mp(0,mp(0,w-x-1)));
        for(int j = 0;j<x;j++){
            int a;
            scanf("%d",&a);
            int l=j,r=j+(w-x);
            while(v.size()){
                if(v.back().x<a){
                    v.back().y.y=l-1;
                    if(v.back().y.x>v.back().y.y){
                        v.pop_back();
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(v.size()&&v.back().x>=a){
                l=v.back().y.y+1;
            }
            v.pb(mp(a,mp(l,r)));
        }
        if(w!=x){
            int l=x,r=w-1;
            int a=0;
            while(v.size()){
                if(v.back().x<a){
                    v.back().y.y=l-1;
                    if(v.back().y.x>v.back().y.y){
                        v.pop_back();
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(v.size()&&v.back().x>=a){
                l=v.back().y.y+1;
            }
            if(l<=r)
            v.pb(mp(a,mp(l,r)));
        }
        for(auto it:v){
           // printf("%d %d %d\n",it.x,it.y.x,it.y.y);
            ans[it.y.x]+=it.x;
            ans[it.y.y+1]-=it.x;
        }
    }
    LL sum=0;
    for(int i=0;i<w;i++){
        sum+=ans[i];
        printf("%lld ",sum);
    }
    printf("\n");
}