#include<cstdio>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,x,i;
    long long sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        sum=sum+x-1;
        if(sum%2==0)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}