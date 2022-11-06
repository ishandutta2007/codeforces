#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200001
using namespace std;
int a[26][26],b[26],n,ans,a1,a2;char c1[mx],c2[mx];
int main(){
    scanf("%d",&n);scanf("%s",c1);scanf("%s",c2);
    rep(i,0,25)rep(j,0,25)a[i][j]=-1;
    rep(i,0,25)b[i]=-1;a1=-1;a2=-1;
    rep(i,0,n-1)if(a[c1[i]-'a'][c2[i]-'a']==-1)
        a[c1[i]-'a'][c2[i]-'a']=i;
    rep(i,0,n-1)if(c1[i]!=c2[i]){
        if(b[c2[i]-'a']==-1)b[c2[i]-'a']=i;ans++;
    }
    rep(i,0,25)rep(j,0,25)
        if(i!=j&&a[i][j]>=0&&a[j][i]>=0){
            printf("%d\n%d %d\n",ans-2,a[i][j]+1,a[j][i]+1);return 0;
        }
    rep(i,0,n-1)if(c1[i]!=c2[i]&&b[c1[i]-'a']>=0){
        printf("%d\n%d %d\n",ans-1,i+1,b[c1[i]-'a']+1);return 0;
    }
    printf("%d\n-1 -1\n",ans);
}