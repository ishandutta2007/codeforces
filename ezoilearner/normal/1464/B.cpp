#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000000ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];int x,y;
int pos[Maxn],sum[Maxn],cnt=0;
ll pre[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	scanf("%s",ch+1);n=strlen(ch+1);
	rd(x);rd(y);
	int c=0,cur=min(x,y),dec=max(x,y)-min(x,y);
	if(x>y)c=1;
	int s=0;
	ll all=0;
	rep(i,1,n){
		sum[i]=sum[i-1];pre[i]=pre[i-1];
		if((ch[i]-'0')==(c^1))sum[i]++,s++;
		if(ch[i]=='?')pos[++cnt]=i,pre[i]++;
		if((ch[i]-'0')==c)all+=sum[i];
	}
	per(i,n,0)
		if((ch[i]-'0')!=c)pre[i]=pre[i+1];
		else pre[i]+=pre[i+1];
	ll Ans=inf;
	rep(i,0,cnt){
		int tmp=cnt-i+s;
		ll h=1ll*cur*tmp*(n-tmp);
		all+=sum[pos[i]];
		h+=1ll*dec*(all+pre[pos[i]+1]-1ll*i*(n-pos[i]-sum[n]+sum[pos[i]]-cnt+i)); 
		Ans=min(Ans,h);
	}
	printf("%lld\n",Ans);
	return 0;
}