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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    int cnt[200005];
    MEM(cnt);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i = k;i>=1;i--){
        cnt[i]+=cnt[i+1];
    }
    int c[200005];
    for(int i = 1;i<=k;i++){
        scanf("%d",&c[i]);
    }
    int ans=0;
    for(int i = 1;i<=k;i++){
        ans=max(ans,(cnt[i]+c[i]-1)/c[i]);
    }
    printf("%d\n",ans);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    vector<vector<int> > res(ans);
    int now=0;
    for(int i = 1;i<=n;i++){
        res[now].pb(a[i]);
        now=(now+1)%ans;
    }
    for(auto it:res){
        printf("%d ",it.size());
        int cnt=0;
        for(auto it2:it){
            printf("%d ",it2);
            cnt++;
            assert(cnt<=c[it2]);
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