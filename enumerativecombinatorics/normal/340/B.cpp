#include<stdio.h>
#include<algorithm>
using namespace std;
double x[500];
double y[500];
double s[500];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%lf%lf",x+i,y+i);
    }
    double ret=0;
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            int N=0;
            for(int k=0;k<a;k++){
                if(k==i)continue;
                if(k==j)continue;
                s[N++]=(x[k]-x[i])*(y[j]-y[i])-(x[j]-x[i])*(y[k]-y[i]);
            }
            std::sort(s,s+a-2);
            ret=max(ret,s[a-3]-s[0]);
        }
    }
    printf("%.12f\n",ret/2);
}