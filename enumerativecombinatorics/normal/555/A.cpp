#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int v=0;
    for(int i=0;i<b;i++){
        int c;scanf("%d",&c);
        int last=0;
        int len=0;
        for(int j=0;j<c;j++){
            int p;scanf("%d",&p);
            if(p==last+1){
                last++;
                len++;
            }
        }
        v=max(v,len);
    }
    printf("%d\n",(a-b-v+1)+(a-v));
}