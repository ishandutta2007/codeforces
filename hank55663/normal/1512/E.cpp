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
static const double INF = 2147483647;
void solve(){
    int n,l,r,s;
    scanf("%d %d %d %d",&n,&l,&r,&s);
    int tot=r-l+1;
    if((1+tot)*tot/2>s)printf("-1\n");
    else if((n+n-tot+1)*tot/2<s)printf("-1\n");
    else{
        vector<int> v;
        int sum=0;
        for(int i = 1;i<=r-l+1;i++)v.pb(i),sum+=i;
        int now=n;
        for(int i = v.size()-1;i>=0;i--){
            int add=min(now-v[i],s-sum);
            sum+=add;
            v[i]+=add;
            now--;
        }
        int vis[505];
        fill(vis,vis+n+1,0);
        for(auto it:v)vis[it]=1;
        queue<int> q;
        for(int i = 1;i<=n;i++){
            if(!vis[i])q.push(i);
        }
        for(int i=1;i<=n;i++){
            if(i<l||i>r)printf("%d ",q.front()),q.pop();
            else{
                printf("%d ",v[i-l]);
            }
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/