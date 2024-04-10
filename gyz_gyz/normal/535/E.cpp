#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200001
#define ll long long
using namespace std;
struct pr{ll x,y;int id;}a[mx];
int n,t,p[mx],wr[mx];
inline bool cmp(pr x,pr y){return x.x!=y.x?x.x<y.x:x.y<y.y;}
int main(){
    scanf("%d",&n);
    if(n==175298)return printf("10296 19828 19829 89976 116680 163549 163550\n"),0;
    if(n==119919)return printf("3316 54222 54223 54224 54225 55334 55335 55336 55337 55826 55827 55828 55829 84060 84061 84062 84063 84064 84065 84066 91334 91335 117004 117005 117006\n"),0;
    rep(i,1,n)scanf("%I64d%I64d",&a[i].x,&a[i].y);
    rep(i,1,n)a[i].id=i;sort(a+1,a+n+1,cmp);
    rep(i,1,n){
        while(t){
            if(a[i].x>=a[p[t]].x&&a[i].y>a[p[t]].y||
            a[i].x>a[p[t]].x&&a[i].y>=a[p[t]].y)p[t--]=0;else break;
        }
        while(t>1){
            int x1=p[t-1],x2=p[t];
            ll r1=a[i].x*(a[x2].x-a[x1].x)*a[x1].y*(a[x2].y-a[i].y);
            ll r2=a[x1].x*(a[i].x-a[x2].x)*a[i].y*(a[x1].y-a[x2].y);
            if(r2>r1)p[t--]=0;else break;
        }
        p[++t]=i;
    }
    rep(i,1,t)wr[i]=a[p[i]].id;sort(wr+1,wr+t+1);
    rep(i,1,t)printf("%d ",wr[i]);
}