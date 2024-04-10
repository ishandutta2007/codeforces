#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    double a,b,x,y,v,answer=INF;
    int n,i;
    scanf("%lf%lf%d",&a,&b,&n);
    for(i=1;i<=n;i++){
        scanf("%lf%lf%lf",&x,&y,&v);
        answer=min(answer,sqrt((a-x)*(a-x)+(b-y)*(b-y))/v);
    }
    printf("%.20f",answer);
    return 0;
}