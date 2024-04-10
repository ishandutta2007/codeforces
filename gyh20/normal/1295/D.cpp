#include<bits/stdc++.h>
#include<map>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return f?-t:t;
}
#define LL long long
LL num[110];
LL que[100010];
LL cnt;
void divid(LL x)
{
    cnt=0;
    for(LL i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                x=x/i;
            }
            num[++cnt]=i;
        }
    }
    if(x!=1)
        num[++cnt]=x;
}
LL solve(LL x)
{
    LL ans=0;
    LL k;
    LL t=0;
    que[0]=-1;
    for(LL i=1;i<=cnt;i++)
    {
        k=t;
        for(LL j=0;j<=k;j++)
        {
            que[++t]=-1*que[j]*num[i];
        }
    }
    for(LL i=1;i<=t;i++)
        ans=ans+(x/que[i]);
    return ans;
}
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
int n,t,x,ans,a,b,c,d;
char s[100002];
int mp[200002];
int cnt0,cnt1;
signed main(){
	t=read();
	while(t--){
		a=read();
		b=read();
		c=gcd(a,b);
		d=b/c-1;
		a/=c;
		b/=c;
		d+=a;
		divid(b);
		printf("%lld\n",(d-a+1)-solve(d)+solve(a-1));
	}
}