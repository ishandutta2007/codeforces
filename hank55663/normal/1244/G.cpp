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
#define MXN 300000
int cnt[1000005];
int c[2][1000005];
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL ans=0;
    for(int i =1;i<=n;i++){
        cnt[i]=1;
        k-=i;
        ans+=i;
    }
    if(k<0){
        printf("-1\n");
        return 0;
    }
    int r=n;
    for(int i=1;i<=n;i++){
        while(k+i-r<0)r--;
        if(i>=r)break;
        cnt[i]--;
        cnt[r]++;
        k=k+i-r;
        ans=ans-i+r;
        r--;
        if(k==0)break;
    }
    int now=1;
    set<int> s1,s2;
    for(int i = 1;i<=n;i++){
        s1.insert(i);
        s2.insert(i);
    }
    for(int i=n;i>=1;i--){
        if(cnt[i]==2){
            c[0][now++]=i;
            c[1][now++]=i;
            s1.erase(i);
            s2.erase(i);
        }
        else if(cnt[i]==1){
            c[0][now++]=i;
            s1.erase(i);
        }
    }
    for(int i = 1;i<=n;i++){
        if(c[0][i]){
            c[1][i]=*s2.rbegin();
            s2.erase(c[1][i]);
        }
        else if(c[1][i]){
            c[0][i]=*s1.rbegin();
            s1.erase(c[0][i]);
        }
        else{
            assert(0);
        }
    }
    printf("%lld\n",ans);
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/