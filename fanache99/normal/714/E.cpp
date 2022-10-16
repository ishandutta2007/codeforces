#include<cstdio>
#include<algorithm>
#define MAXN 3010
using namespace std;
long long v[MAXN],aux[MAXN],solution[MAXN];
long long modul(long long x){
    if(x<0)
        return -x;
    return x;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,j,position;
    long long k,sum=0,current,minim;
    scanf("%d",&n);
    k=1;
    for(i=1;i<=n;i++){
        scanf("%I64d",&v[i]);
        v[i]=v[i]-(i-1)*k;
        aux[i]=v[i];
    }
    sort(aux+1,aux+n+1);
    for(i=1;i<=n;i++){
        solution[i]=aux[n];
        sum+=modul(solution[i]-v[i]);
    }
    for(i=n-1;i>=1;i--){
        current=sum;
        minim=sum;
        for(j=1;j<=n;j++){
            current-=modul(solution[j]-v[j]);
            current+=modul(aux[i]-v[j]);
            if(current<minim){
                minim=current;
                position=j;
            }
        }
        if(minim<sum){
            sum=minim;
            for(j=1;j<=position;j++)
                solution[j]=aux[i];
        }
    }
    printf("%I64d",sum);
    return 0;
}