#include <stdio.h>
int n,cnt,x,ans,now,bx[110];
int main(){
    scanf("%d",&n); while( n-- ){
        scanf("%d",&x); if( x<0 ){
            if( cnt==2 ) bx[ans]=now,ans++,now=cnt=1;
            else cnt++,now++;
        }else now++;
    }
    bx[ans]=now; printf("%d\n",ans+1);
    for( int i=0;i<=ans;i++ ) printf("%d%c",bx[i],i==ans?'\n':' ');
}