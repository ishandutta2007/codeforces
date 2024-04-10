#include <cstdio>
#include <cmath>
using namespace std;
double n,r,R;
double ang;
const double PI=4*atan(1);
int main(){
    scanf("%lf%lf%lf",&n,&R,&r);
    if (n==1 && r<=R){
        printf("YES\n");
        return 0;
    }
    ang=asin(r/(R-r));
    if (n-0.000001<=PI/ang) printf("YES\n");
    else printf("NO\n");
}