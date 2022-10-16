#include<stdio.h>
#include<string.h>
using namespace std;
char s[101],e[101];
int max=0,nr,n;
void search(int l){
    int i,pp,j;
    nr=0;
    for(i=0;i<=n-l;i++){
        pp=1;
        for(j=i;j<=i+l-1&&pp==1;j++)
            if(s[j]!=e[j-i])
                pp=0;
        if(pp==1)
            nr++;
    }
    if(nr>=2&&l>max)
        max=l;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int i,j,k,l;
    scanf("%s",&s);
    n=strlen(s);
    for(k=1;k<=n;k++)
        for(j=0;j<=n-k;j++){
            l=-1;
            for(i=j;i<=j+k-1;i++){
                l++;
                e[l]=s[i];
            }
            e[l+1]=NULL;
            search(l);
        }
    printf("%d",max);
    return 0;
}