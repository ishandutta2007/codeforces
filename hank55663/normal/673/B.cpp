#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long  fpow(long long int a,int k){
    long long int temp=a,ans=1;
    while(k){
        if(k&1)ans=ans*temp;
        temp=temp*temp;
        k>>=1;
    }
    return ans;
}
main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int belong[100005];
    memset(belong,0,sizeof(belong));
    int ok=1;
    int ma=1,mi=n;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b)
            swap(a,b);
        if((belong[a]==0||belong[a]==1)&&(belong[b]==0||belong[b]==2))
            belong[a]=1,belong[b]=2,ma=max(ma,a),mi=min(b,mi);
        else
            ok=0;
    }
    if(ok==0||mi<=ma)
        printf("0\n");
    else{
        printf("%d",mi-ma);
    }
}