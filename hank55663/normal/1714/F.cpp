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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,d[3];
    scanf("%d %d %d %d",&n,&d[0],&d[1],&d[2]);
    LL sum=d[0]+d[1]+d[2];
    if(sum%2==1){printf("NO\n");return;}
    sum/=2;
    LL a[3]={sum-d[0],sum-d[1],sum-d[2]};
    if(a[0]+a[1]+a[2]+1>n||a[0]<0||a[1]<0||a[2]<0){
        printf("NO\n");
    }
    else{
        int sum=0;
        for(int j = 0;j<3;j++){
            if(a[j]==0){
                sum++;
            }
        }
        if(sum>1){
            printf("NO\n");
            return;
        }
        int now=5;
        vector<pii> v;
        int last=4;
        if(a[0]==0)now=4,last=3;
        if(a[1]==0)now=4,last=1;
        if(a[2]==0)now=4,last=2;
        for(int j = 1;j<a[0];j++){
            v.pb(mp(last,now));
            last=now;
            now++;
        }
        if(last!=3)
        v.pb(mp(last,3));
        last=4;
                if(a[0]==0)last=3;
        if(a[1]==0)last=1;
        if(a[2]==0)last=2;
        for(int j = 1;j<a[1];j++){
            v.pb(mp(last,now));
            last=now;
            now++;
        }
        if(last!=1)
        v.pb(mp(last,1));
        last=4;
        if(a[0]==0)last=3;
        if(a[1]==0)last=1;
        if(a[2]==0)last=2;
        for(int j = 1;j<a[2];j++){
            v.pb(mp(last,now));
            last=now;
            now++;
        }
        if(last!=2)
        v.pb(mp(last,2));
        last=4;
            if(a[0]==0)last=3;
        if(a[1]==0)last=1;
        if(a[2]==0)last=2;
        while(now<=n){
            v.pb(mp(last,now++));
        }
        printf("YES\n");
        for(auto it:v){
            printf("%d %d\n",it.x,it.y);
        }
    }
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/