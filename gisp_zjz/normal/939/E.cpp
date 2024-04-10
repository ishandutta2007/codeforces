#include<bits/stdc++.h>
#define maxn 904030

using namespace std;
double a[maxn],s[maxn];
int n,k,query,o;

int main()
{
    scanf("%d",&query); n=0; k=1;
    while (query--)
    {
        scanf("%d",&o);
        if (o==1){scanf("%lf",&a[++n]); s[n]=s[n-1]+a[n];}
        else{
            while (k<n&&(s[k+1]+a[n])/(k+2)<(s[k]+a[n])/(k+1)) k++;
            printf("%.10f\n",a[n]-(s[k]+a[n])/(k+1));
        }
    }
    return 0;
}