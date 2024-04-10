#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
    re int t=0,f=0;re char v=getchar();
    while(v<'0')f|=(v=='-'),v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return f?-t:t;
}
int n,a[3002],ans[3002],k,sum,ans1,ans2,p[3002],tot;
char s[3002];
struct node{
    int x,y;
}q[3002];
signed main(){
    n=read();k=read();
    scanf("%s",s+1);sum=1;
    for(re int i=1;i<=n;++i){

        if(s[i]=='L'){
            ans[i]=sum;
            ans1=max(ans1,i-ans[i]);ans2+=i-ans[i];
            ++sum;//printf("%lld %lld\n",i,ans[i]);
            if(i!=ans[i])q[++tot]=(node){ans[i],i};
        }
    }//return 0;
    if(ans2<k){
        puts("-1");
        return 0;
    }ans1=0;
    while(tot){
        re int num=0,lst=0,sss=0;
        for(re int i=1;i<=tot;++i){
            node z=q[i];
            if(z.y==lst+1){
                lst=z.y;
                q[++sss]=z;
                continue;
            }lst=z.y;
            --z.y;
            if(z.x!=z.y)q[++sss]=z;
        }++ans1;tot=sss;
    if(ans1>k){
        puts("-1");
        return 0;
    }
    }
    sum=1;ans2=0;
    for(re int i=1;i<=n;++i){
        if(s[i]=='L'){
            ans[i]=sum;
            ans2+=i-ans[i];
            ++sum;//printf("%lld %lld\n",i,ans[i]);
            if(i!=ans[i])q[++tot]=(node){ans[i],i};
        }
    }
    while(tot){
        re int sss=0,y=min(ans2-k+1,tot),num=0,lst=0;
        if(y==1){
            for(re int i=1;i<=tot;++i){
                node z=q[i];
                while(z.y!=z.x){
                    --z.y;
                    printf("%d %d\n",1,z.y);
                }
            }
            return 0;
        }
        for(re int i=1;i<=tot;++i){
            node z=q[i];
            if(z.y==lst+1||num>=y){lst=z.y;
                q[++sss]=z;
                continue;
            }lst=z.y;
            p[++num]=(--z.y);--ans2;if(z.x!=z.y)q[++sss]=z;
        }--k;tot=sss;
        printf("%lld ",num);
        for(re int i=1;i<=num;++i)printf("%lld ",p[i]);
        putchar('\n');
    }
}