#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a,b,c;
int main(){
    scanf("%d",&n);
    while (n--){
        int ans=0;
        scanf("%d%d%d",&a,&b,&c);
        if (a<b) swap(a,b);
        if (a<c) swap(a,c);
        if (b<c) swap(b,c);
        ans=b-c;
        b-=ans;
        a-=ans;
        if (a>=b+c){
            ans+=b+c;
        }
        else{
            b-=(a>>1);
            c-=(a>>1);
            if (a&1){
                c--;
            }
            ans+=a;
            ans+=min(b,c);
        }
        printf("%d\n",ans);
    }
}