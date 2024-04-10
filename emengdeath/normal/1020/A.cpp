#include<bits/stdc++.h>
using namespace std;
int n,a,b,h,ta,fa,tb,fb,k;
int main(){
    scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
    while (k--){
        scanf("%d %d %d %d",&ta,&fa,&tb,&fb);
        if (ta==tb){
            printf("%d\n",abs(fa-fb));
            continue;
        }
        int ans=abs(ta-tb);
        if (fa>fb)swap(fa,fb);
        if (fa<=a){
            ans+=a-fa;
            if (fb<=a)ans+=a-fb;
            else
                ans+=fb-a;
        }else
        if (fa<=b){
            ans+=fb-fa;
        }else{
            ans+=fa+fb-b-b;
        }
        printf("%d\n",ans);
    }
    return 0;
}