#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+200;
const int M=1000000007;
int _,n,p,k,x,y,ans,val[maxn];
char s[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d%d",&n,&p,&k); --p;
        scanf("%s",s);
        scanf("%d%d",&x,&y);
        for (int i=n-k;i<n;i++) val[i]=x*(s[i]=='0');
        for (int i=n-k-1;i>=p;i--) val[i]=val[i+k]+x*(s[i]=='0');
        ans=M;
        for (int i=p;i<n;i++) ans=min(ans,val[i]+y*(i-p));
        printf("%d\n",ans);
    }
    return 0;
}