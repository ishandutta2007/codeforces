#include<cstdio>
using namespace std;
long long nrp[60];
int sol[60];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i;
    long long k;
    scanf("%d%I64d",&n,&k);
    nrp[0]=nrp[1]=1;
    for(i=2;i<=n;i++)
        nrp[i]=nrp[i-1]+nrp[i-2];
    for(i=1;i<=n;i++)
        if(k<=nrp[n-i])
            sol[i]=i;
        else{
            sol[i]=i+1;
            sol[i+1]=i;
            k-=nrp[n-i];
            i++;
        }
    for(i=1;i<=n;i++)
        printf("%d ",sol[i]);
    return 0;
}