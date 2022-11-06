#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 100010
#define inf 2000000000
using namespace std;
long long a[mx],b[mx],s[mx],d[mx],q[mx],t,j,mi,ans,L,R,M;int n;
int main(){
    scanf("%d",&n);ans=inf;
    rep(i,0,n+1)scanf("%I64d",&s[i]);
    rep(i,1,n)scanf("%I64d",&d[i]);d[0]=inf;d[n+1]=inf;b[n]=n+1;
    rep(i,2,n){j=i-1;
        while((s[i]-s[a[j]])/2>d[j])j=a[j];a[i]=j;
    }
    dep(i,n-1,1){j=i+1;
        while((s[b[j]]-s[i])/2>d[j])j=b[j];b[i]=j;
    }
    rep(i,0,n+1)a[i]=s[a[i]]+d[i]*2,b[i]=s[b[i]]-d[i]*2;
    rep(i,1,n+1){
        if(a[i-1]>s[i-1]){
            while(t&&a[q[t]]<a[i-1])t--;q[++t]=i-1;
        }
        if(b[i]<s[i]){
            for(L=1,R=t,M=(L+R+1)/2;L<R;M=(L+R+1)/2)
                if(b[i]<=a[q[M]])L=M;else R=M-1;
            if(s[i]-s[q[M]]<ans)ans=s[i]-s[q[M]];
            for(L=1,R=t,M=(L+R+1)/2;L<R;M=(L+R+1)/2)
                if(s[i]<=a[q[M]])L=M;else R=M-1;
            if(b[i]<=s[q[M]]&&(i!=n+1||q[M]!=0)){
                printf("0\n");return 0;
            }
        }
    }
    printf("%.1lf\n",1.0*ans/2);
}