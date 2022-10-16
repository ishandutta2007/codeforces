#include<stdio.h>
using namespace std;
char s[1001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    char c;
    int k=0,nr=0,l,ss=0;
    while(scanf("%c",&c)!=EOF)
        if(c!='\n'){
            s[k]=c;
            k++;
        }
        else{
            s[k]=NULL;
            if(s[0]=='+')
                nr++;
            if(s[0]=='-')
                nr--;
            if(s[0]!='+'&&s[0]!='-'){
                k=0;
                l=0;
                while(s[k]!=':')
                    k++;
                k++;
                while(s[k]!=NULL){
                    l++;
                    k++;
                }
                ss=ss+l*nr;
            }
            k=0;
        }
    printf("%d",ss);
    return 0;
}