#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int bln[200005];
int Find(int x){
    if(bln[x]==x)return x;
    return bln[x]=Find(bln[x]);
}
int main() {

    int t;
    scanf("%d",&t);
    pii p[200005];
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(y,x);
            bln[i]=i;
        }
        bln[n]=n;
        sort(p,p+n);
        reverse(p,p+n);
        LL ans=0;
        for(int i = 0;i<n;i++){
            int x=Find(p[i].y);
          //  printf("%d\n",x);
            if(x==n){
                ans+=p[i].x;
            }
            else{
                bln[x]=x+1;
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}