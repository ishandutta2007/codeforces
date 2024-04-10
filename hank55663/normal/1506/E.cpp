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
    int n;
    scanf("%d",&n);
    int q[200005];
    int p[200005];
    fill(p,p+n+1,0);
    for(int i = 0;i<n;i++){
        scanf("%d",&q[i]);
    }
    p[0]=q[0];
    for(int i = 1;i<n;i++){
        if(q[i]!=q[i-1])p[i]=q[i];
    }
    deque<int> qq;
    int now=1;
    for(int i = 0;i<n;i++){
        if(p[i]){
            printf("%d ",p[i]);
            for(int j = now;j<p[i];j++)qq.push_back(j);
            now=p[i]+1;
        }
        else{
            printf("%d ",qq.front());
            qq.pop_front();
        }
    }
    now=1;
    printf("\n");
    for(int i = 0;i<n;i++){
        if(p[i]){
            printf("%d ",p[i]);
            for(int j = now;j<p[i];j++)qq.push_back(j);
            now=p[i]+1;
        }
        else{
            printf("%d ",qq.back());
            qq.pop_back();
        }
    }
    printf("\n");
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