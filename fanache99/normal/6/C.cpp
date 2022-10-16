#include<stdio.h>
using namespace std;
int v[100001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,a,b,nr1=0,nr2=0;
    scanf("%d",&n);
    a=1;
    b=n;
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    if(n==1)
        printf("1 0");
    else{
        while(a<=b)
            if(v[a]==v[b]){
                nr1++;
                nr2++;
                a++;
                b--;
                if(a==b){
                    nr1++;
                    a++;
                }
            }
            else
                if(v[a]<v[b]){
                    nr1++;
                    a++;
                    v[b]-=v[a-1];
                    if(a==b){
                        a++;
                        nr2++;
                    }
                }
                else{
                    nr2++;
                    b--;
                    v[a]-=v[b+1];
                    if(a==b){
                        b--;
                        nr1++;
                    }
                }
        printf("%d %d",nr1,nr2);
    }
    return 0;
}