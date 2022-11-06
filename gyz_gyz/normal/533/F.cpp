#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 300000
#define mo 10000000000000007ll
using namespace std;
map<long long,int>A;
char a[mx],b[mx];
int n,m,u,ans,ct[26],wr[mx];
long long s1[26],s2[26],t;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);scanf("%s",b+1);
    rep(i,1,m)rep(j,0,25)s1[j]=(s1[j]*2+(a[i]-'a'==j))%mo;
    rep(i,1,m)rep(j,0,25)s2[j]=(s2[j]*2+(b[i]-'a'==j))%mo;
    rep(i,0,25)A[s1[i]]=i+1;
    t=1;rep(i,1,m-1)t=t*2%mo;
    rep(i,0,25)if(!ct[i]&&s2[i]){
        int op=A[s2[i]]-1;
        if(op==i)ct[i]=1,A[s1[i]]=0;else{
            if(op<0||s1[i]!=s2[op]){u=1;break;}
            else ct[i]=1,ct[op]=1,A[s1[i]]=0,A[s2[i]]=0;
        }
    }
    if(!u)wr[++ans]=1;
    rep(i,m+1,n){
        A.clear();rep(j,0,25)ct[j]=0;u=0;
        rep(j,0,25)s1[j]=((s1[j]+mo-t*(a[i-m]-'a'==j))*2+(a[i]-'a'==j))%mo;
        rep(j,0,25)A[s1[j]]=j+1;
        rep(j,0,25)if(!ct[j]&&s2[j]){
            int op=A[s2[j]]-1;
            if(op==j)ct[j]=1,A[s1[j]]=0;else{
                if(op<0||s1[j]!=s2[op]){u=1;break;}
                else ct[j]=1,ct[op]=1,A[s1[j]]=0,A[s2[j]]=0;
            }
        }
        if(!u)wr[++ans]=i-m+1;
    }
    printf("%d\n",ans);
    rep(i,1,ans)printf("%d ",wr[i]);
}