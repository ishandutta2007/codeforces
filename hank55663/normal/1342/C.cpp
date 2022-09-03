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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
LL cnt[100005];
LL cal(LL x,int a,int b){
    LL ans=x/(a*b)*cnt[a*b-1];
    ans+=cnt[x%(a*b)];
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,q;
        scanf("%d %d %d",&a,&b,&q);
        MEM(cnt);
        for(int i = 0;i<a*b;i++){
            if(i%a%b!=i%b%a)cnt[i]++;
            if(i!=0)cnt[i]+=cnt[i-1];
        }
        while(q--){
            LL l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld ",cal(r,a,b)-cal(l-1,a,b));
        }
        printf("\n");
    }
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/