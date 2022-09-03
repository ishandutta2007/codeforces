#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005

int main(){
    int m,n,k,t;
    scanf("%d %d %d %d",&m,&n,&k,&t);
    int a[200005];
    for(int i = 0;i<m;i++)
        scanf("%d",&a[i]);
    sort(a,a+m);
    vector<pii> v[200005];
    //fill(Max,Max+200005,0);
    for(int i = 0;i<k;i++){
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        v[d].pb(mp(l,r));
        //Max[d]=max(Max[d],r);
    }
    int Max=200001,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        vector<pii> tmp;
        for(int i = mid;i<=200000;i++){
            for(auto it:v[i]){
                tmp.pb(it);
            }
        }
        int cnt[200005];
        fill(cnt,cnt+n+1,0);
        for(auto it:tmp){
            cnt[it.x-1]++;
            cnt[it.y]--;
        }
        int tot=0,sum=0;
        for(int i = 0;i<=n;i++){
            sum+=cnt[i];
            if(sum)tot++;
        }
       // printf("%d %d\n",mid,tot);
        if(tot*2+n+1>t)Min=mid;
        else Max=mid;
    }
    //printf("%d %d\n",Max,Min);
    int ans=0;
    for(int i = 0;i<m;i++)
        if(a[i]>=Min)ans++;
    printf("%d\n",ans);
}