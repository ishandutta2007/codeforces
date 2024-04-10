#include<bits/stdc++.h>
using namespace std;
const int maxn=7e5+6;
int n,a[maxn],l,r,ans,mn,val,ans2,lp,rp,sum[maxn],s2[maxn];
char s[maxn];

int main(){
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;i++) if (s[i]=='(') a[i]=a[i-1]+1; else a[i]=a[i-1]-1;
    if (a[n]!=0){
        printf("0\n1 1\n");return 0;
    }
    for (int i=1;i<=n;i++) mn=min(mn,a[i]);
    for (int i=1;i<=n;i++) if (a[i]==mn) ++ans;
    for (int i=1;i<=n;i++) if (a[i]==mn+1) ++ans2;
    val=ans;l=1;r=1;
    for (int i=1;i<=n;i++) a[i+n]=a[i]; n<<=1;
    for (int i=0;i<n/2;i++) if (a[i]==mn+1&&a[i+1]==mn+2){
        int L=i+1,R=L,ret=0;
        while (a[R]>=mn+2){
            if (a[R]==mn+2) ++ret;
            R++;
        }
        if (val<ret+ans) val=ret+ans,l=L,r=R;
    }
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]==mn);
    for (int i=1;i<=n;i++) s2[i]=s2[i-1]+(a[i]==mn+1);
    int j=0;
    for (int i=1;i<=n/2;i++){
        if (a[i]!=mn) continue;
        while (sum[j]-sum[i-1]<ans) ++j;
        if (val<ans2-(s2[j]-s2[i-1])) val=ans2-(s2[j]-s2[i-1]),l=i,r=j+1;
    }
    if (l>n/2) l-=n/2;
    if (r>n/2) r-=n/2;
    printf("%d\n",val);
    printf("%d %d\n",l,r);
}