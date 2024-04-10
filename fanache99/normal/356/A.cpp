#include<cstdio>
using namespace std;
int urm[300010],dad[300010];
int find_next(int elem){
    if(urm[elem]==elem)
        return elem;
    int x=find_next(urm[elem]);
    urm[elem]=x;
    return x;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,i,a,b,x,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n+1;i++)
        urm[i]=i;
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&x);
        k=a;
        while(k<=b){
            k=find_next(k);
            if(k!=x){
                if(k<=b){
                    dad[k]=x;
                    if(k>x)
                        urm[k]=urm[b+1];
                    else
                        urm[k]=x;
                }
                k++;
            }
            else
                k=x+1;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",dad[i]);
    return 0;
}