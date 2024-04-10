#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[3000005];
int g;
bool go(int i){
    int l=2*i,r=2*i+1;
    if(a[l]==0&&a[r]==0){
        if(i<(1<<g)){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if(a[l]>a[r])return go(l);
        else return go(r);
    }
}
int f(int i){
    int l=2*i,r=2*i+1;
    if(a[l]==0&&a[r]==0)a[i]=0;
    else{
        if(a[l]>a[r]){
            a[i]=a[l];
            f(l);
        }
        else{
            a[i]=a[r];
            f(r);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL sum=0;
        int h;
        scanf("%d %d",&h,&g);
        for(int i = 1;i<(1<<h);i++){
            scanf("%d",&a[i]);
         //   a[i]=i;
            sum+=a[i];
        }
        /*random_shuffle(a+1,a+(1<<h));
        for(int i = (1<<h)-1;i>=1;i--){
            if(a[i]<a[2*i+1]){
                swap(a[i],a[2*i+1]);
            }
            if(a[i]<a[2*i]){
                swap(a[i],a[2*i]);
            }
        }*/
        priority_queue<pii> pq;
        pq.push(mp(a[1],1));
        vector<int> ans;
        for(int i = 0;i<(1<<h)-(1<<g);i++){
            while(true){
                pii p=pq.top();
                pq.pop();
                if(go(p.y)){
                    sum-=p.x;
                    ans.pb(p.y);
                    f(p.y);
                    pq.push(mp(a[p.y],p.y));
                    break;
                }
                else{
                 //   if(go(p.y*2)){
                    pq.push(mp(a[2*p.y],2*p.y));
                  //  }
                  //  if(go(p.y*2+1)){
                    pq.push(mp(a[2*p.y+1],2*p.y+1));
                   // }
                }
            }
           // printf("%d\n",sum);
        }
        printf("%lld\n",sum);
        for(auto it:ans){
            printf("%d ",it);
        }
        printf("\n");
        fill(a,a+(1<<h),0);
    }
}
/*

*/