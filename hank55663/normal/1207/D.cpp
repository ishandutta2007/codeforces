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
bool cmp(const pii &p,const pii &q){
    return p.y<q.y;
}
LL fra[300005];
int mod=998244353;
int main(){
    fra[0]=1;
    for(int i = 1;i<=300000;i++)
        fra[i]=fra[i-1]*i%mod;
    int n;
    scanf("%d",&n);
    pii p[300005];
    for(int i = 0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
    }
    sort(p,p+n);
    LL ans=fra[n];
    LL sub=1;
    int cnt=0;
    int last=0;
    for(int i = 0;i<n;i++){
        if(p[i].x==last){
            cnt++;
        }  
        else{
            sub=sub*fra[cnt]%mod;
            last=p[i].x;
            cnt=1;
        }
    }
    sub*=fra[cnt]%mod;
    ans-=sub;
    sort(p,p+n,cmp);
    sub=1;
    last=0;
    cnt=0;
    for(int i = 0;i<n;i++){
        if(p[i].y==last){
            cnt++;
        }  
        else{
            sub=sub*fra[cnt]%mod;
            last=p[i].y;
            cnt=1;
        }
    }
    sub*=fra[cnt]%mod;
    ans-=sub;
    sort(p,p+n);
    int ok=1;
    for(int i = 0;i<n-1;i++){
        if(p[i].y>p[i+1].y)ok=0;
    }
    if(ok){
        sub=1;
        pii Last=mp(0,0);
        //last=0;
        cnt=0;
        for(int i = 0;i<n;i++){
            if(p[i]==Last){
                cnt++;
            }  
            else{
                sub=sub*fra[cnt]%mod;
                Last=p[i];
                cnt=1;
            }
        }
        sub*=fra[cnt]%mod;
        ans+=sub;
    }
    ans=(ans%mod+mod)%mod;
    printf("%lld\n",ans);
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
24
 */