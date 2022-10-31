#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int c[210000];
int z[210000];
map<int,int> ans;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",c+i);
        z[i]=c[i];
        ans[c[i]]=i;
    }
    z[a++]=-2010000000;
    z[a++]=2010000000;
    std::sort(z,z+a);
    
    for(int i=0;i<b;i++){
        int p,q;scanf("%d%d",&p,&q);
        int at=c[p-1];
        int len=q;
        int lr=-1000000007;
        int ll=-1000000007;
        while(1){
            bool turn=false;
            int use=0;
            int to=*(upper_bound(z,z+a,at+len)-1);
            if(to>at){
                turn=true;
                use+=to-at;
                len-=to-at;
                at=to;
            }
            int to2=*(lower_bound(z,z+a,at-len));
            if(to2<at){
                turn=true;
                use+=at-to2;
                len-=at-to2;
                at=to2;
            }
            if(!turn)break;
            if(lr==to&&ll==to2){
                len%=use;
            }
            lr=to;
            ll=to2;
        }
        printf("%d\n",ans[at]+1);
    }
}