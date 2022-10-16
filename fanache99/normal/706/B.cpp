#include<cstdio>
#include<algorithm>
#define MAXN 100010
using namespace std;
int v[MAXN];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,q,r,x,left,right,middle,answer;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d",&x);
        left=1;
        right=n;
        answer=0;
        while(left<=right){
            middle=(left+right)/2;
            if(v[middle]<=x){
                answer=middle;
                left=middle+1;
            }
            else
                right=middle-1;
        }
        printf("%d\n",answer);
    }
    return 0;
}