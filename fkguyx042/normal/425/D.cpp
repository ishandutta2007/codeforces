#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define MAXN 100010
struct node{int x,y;
    inline int operator <(const node &a){
        return a.x!=x?x<a.x:y<a.y;
    }inline int operator ==(const node &a){
        return x==a.x&&y==a.y;
    }
}g[MAXN],tmp;
int numx[MAXN],numy[MAXN],totx,toty,n;
set<int>x[MAXN],y[MAXN];long long ans;
#define it set<int>::iterator
inline int cmp(const node &a,const node &b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}
inline int find(const int &x,const int &y){
    int l=1,r=n;tmp=(node){x,y};for(;l<=r;){
        int mid=(l+r)>>1;
        if(g[mid]==tmp)return 1;
        else if(g[mid]<tmp)l=mid+1;else r=mid-1;
    }return 0;
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;i++){
        scanf("%d%d",&g[i].x,&g[i].y);
        numx[++totx]=g[i].x;numy[++toty]=g[i].y;
    }sort(numx+1,numx+totx+1);sort(numy+1,numy+toty+1);
    sort(g+1,g+n+1,cmp);
    totx=unique(numx+1,numx+totx+1)-(numx+1);
    toty=unique(numy+1,numy+toty+1)-(numy+1);
    for(int i=1;i<=n;i++){
        int tmp=lower_bound(numx+1,numx+totx+1,g[i].x)-(numx+1);x[tmp].insert(g[i].y);
        tmp=lower_bound(numy+1,numy+toty+1,g[i].y)-(numy+1);y[tmp].insert(g[i].x);
    }
    for(int i=1;i<=n;i++){
        it down,right;
        int tmp1=lower_bound(numx+1,numx+totx+1,g[i].x)-(numx+1),
            tmp2=lower_bound(numy+1,numy+toty+1,g[i].y)-(numy+1);
        right=x[tmp1].lower_bound(g[i].y);
        down=y[tmp2].lower_bound(g[i].x);down++;right++;
        for(;right!=x[tmp1].end()&&down!=y[tmp2].end();){
            if(*right-g[i].y==*down-g[i].x){
                if(find(*down,*right))ans++;down++;right++;
            }else if(*right-g[i].y<*down-g[i].x)right++;else down++;
        }
    }printf("%I64d\n",ans);
}