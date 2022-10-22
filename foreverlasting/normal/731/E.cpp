//2018.7.30 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline int _max(res x,res y){
    return x>y?x:y;
}
inline int _min(res x,res y){
    return x<y?x:y;
}
const int N=2*1e5+10;
int n;
int a[N],dp[N];
int main(){
	n=read();
	for(res i=1;i<=n;i++)a[i]=a[i-1]+read();
	res ans=a[n];
	for(res i=n-1;i>=1;i--)dp[i]=ans,ans=_max(ans,a[i]-dp[i]);
    printf("%d\n",dp[1]);
	return 0;
}