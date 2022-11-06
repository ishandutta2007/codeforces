#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n;long long a,b,l,t,m,L,R,M;
int main(){
    scanf("%I64d%I64d%d",&a,&b,&n);
    rep(i,1,n){
        scanf("%I64d%I64d%I64d",&l,&t,&m);
        if(a+(l-1)*b>t){
            printf("-1\n");continue;
        }
        for(L=l,R=(t-a)/b+1,M=(L+R+1)/2;L<R;M=(L+R+1)/2)
            if((a*2+(l+M-2)*b)*(M-l+1)/2<=t*m)L=M;else R=M-1;
        printf("%I64d\n",M);
    }
}