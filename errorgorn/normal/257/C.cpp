#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<double> v;
const double PI=4*atan(-1);
int main(){
    scanf("%d",&n);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        if (a<0){
            v.push_back(atan((double)b/a)/PI*180+45);
        }
        else{
            v.push_back(atan((double)b/a)/PI*180+225);
        }
    }

    sort(v.begin(),v.end());

    double m=v[0]-v[n-1]+360;

    for (int x=1;x<n;x++) m=max(m,v[x]-v[x-1]);

    printf("%.8f\n",360-m);
}