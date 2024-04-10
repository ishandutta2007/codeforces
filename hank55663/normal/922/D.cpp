#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
bool cmp(const pair<pii,string> &p1,const pair<pii, string> &p2){
    if(p1.x.x==0&&p2.x.x==0){
        return p1.y<p2.y;
    }
    else if(p1.x.y==0&&p2.x.y==0){
        return p1.y<p2.y;
    }
    if(p1.x.x==0)
    return false;
    if(p1.x.y==0)
    return true;
    if(p2.x.x==0)
    return true;
    if(p2.x.y==0)
    return false;
    return (LL)p1.x.x*p2.x.y>(LL)p1.x.y*p2.x.x;
}
int main(){
    int n;
    scanf("%d",&n);
    pair<pii,string> p[100005];
    for(int i = 0;i<n;i++){
        char c[100005];
        scanf("%s",c);
        int s=0,h=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='s')
            s++;
            else 
            h++;
        }
        p[i]=mp(mp(s,h),string(c));
    }
    sort(p,p+n,cmp);
    int cnt=0;
    LL ans=0;
    for(int i = 0;i<n;i++){
        for(auto it:p[i].y){
            if(it=='s')
            cnt++;
            else
            ans+=cnt;
        }
    }
    printf("%lld\n",ans);
}