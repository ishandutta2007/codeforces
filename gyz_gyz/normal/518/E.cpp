#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200001
using namespace std;
int a[mx],b[mx],n,k,x,y;char ch[10];
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%s",ch);
        if(ch[0]=='?')b[i]=1;else sscanf(ch,"%d",&a[i]);
    }
    rep(i,1,k)a[n+i]=1010000000;n+=k;
    rep(i,1,k){
        y=-1010000000;x=0;
        rep(j,0,(n-i)/k){
            int w=i+j*k;
            if(b[w])x++;else{
                if(a[w]-y-1<x){
                    printf("Incorrect sequence\n");
                    return 0;
                }
                if(a[w]<=x/2+1)rep(l,1,x)w-=k,a[w]=a[w+k]-1;
                else if(y>=-x/2-1){
                        w-=(x+1)*k;rep(l,1,x)w+=k,a[w]=a[w-k]+1;
                    }else{
                        w-=(x+1)/2*k;rep(l,1,(x+1)/2-1)w+=k,a[w]=a[w-k]+1;
                        w-=((x+1)/2-1)*k;rep(l,1,x-(x+1)/2)w-=k,a[w]=a[w+k]-1;
                    }
                x=0;y=a[i+j*k];
            }
        }
    }
    rep(i,1,n-k)printf("%d ",a[i]);
}