#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
#define For(i,a,b) for(int i=(a);i<int(b);i++)
#define N 1000010
int p[N],q[N],n,cnt[N];
int vis[N];
int main(){
    memset(cnt,-1,sizeof(cnt));
    scanf("%d",&n);
    For(i,0,n)scanf("%d",p+i),p[i]--;
    For(i,0,n)if(!vis[i]){
        int sz=0,j=i;
        do{
            vis[j]=1;
            sz++;
            j=p[j];
        }while(j!=i);
        if(sz%2==1){
            int k=i;
            For(l,0,sz/2+1)k=p[k];
            do{
                q[j]=k;
                k=p[k];
                j=p[j];
            }while(j!=i);
        }else if(cnt[sz]==-1){
            cnt[sz]=i;
        }else{
            int k=cnt[sz];
            do{
                q[j]=k;
                j=p[j];
                q[k]=j;
                k=p[k];
            }while(j!=i);
            cnt[sz]=-1;
        }
    }
    For(i,0,n)if(cnt[i]!=-1){
        puts("-1");
        return 0;
    }For(i,0,n)printf("%d ",q[i]+1);
}