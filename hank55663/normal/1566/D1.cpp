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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 3000000
int mod=1e9+7;
bool cmp(const pii &p,const pii &q){
    if(p.x!=q.x)return p.x<q.x;
    else return p.y>q.y;
}
void solve(int T){
    int n,m;
    scanf("%d %d",&n,&m);
    pii a[305];
    for(int i = 0;i<m;i++){
        int x;
        scanf("%d",&x);
        a[i]=mp(x,i);
    }
    sort(a,a+m,cmp);
    for(int i = 0;i<m;i++){
        a[i].x=i;
        swap(a[i].x,a[i].y);
    }
    sort(a,a+m);
    LL ans=0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<i;j++){
            if(a[j].y<a[i].y)ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve(i);
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/