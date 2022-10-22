#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int query(int x){
    printf("%d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    if(t==0){
        exit(0);
    }
    return t;
}

int main(){
    int n,m;
    bool lie[35];
    scanf("%d%d",&m,&n);
    for(register int i=0;i<n;++i){
        int t=query(1);
        lie[i]=(t!=1);
    }
    int l=2,r=m;
    for(int q=0;;++q){
        int mid=(l+r)>>1;
        int t=query(mid);
        if(lie[q%n])t=-t;
        if(t==-1)r=mid-1;
        else l=mid+1;
    }
    return 0;
}