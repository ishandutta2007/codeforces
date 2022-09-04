#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
LL S[400005];
void add(LL x,int k){
	for(int i=x;i<400005;i+=i&-i)
	S[i]+=k;
}
int query(int l,int r){
	LL res1=0,res2=0;
	for(int i=l-1;i>0;i-=i&-i){
		res1+=S[i];
	}
	for(int i=r;i>0;i-=i&-i){
		res2+=S[i];
	}
	LL need=(res1+res2)/2;
//	printf("%lld\n",need);
	int ret=0;
	LL now=0;
//	printf("%d\n",1<<17);
	for(int i=17;i>=0;i--){
		if(now+S[ret+(1<<i)]<=need){
			ret+=(1<<i);
			now+=S[ret];
		}
	}
//	printf("%d\n",now);
	return ret+1;
}
int mod=1e9+7;
LL s1[200005];
LL s2[200005];
LL s3[200005];
LL s4[200005];
void add1(LL *s,int x,LL k){
	for(int i=x;i<200005;i+=i&-i){
		s[i]+=k;
		s[i]=(s[i]%mod+mod)%mod;
	}
} 
LL query1(LL *s,int x){
	LL res=0;
	for(int i=x;i>0;i-=i&-i){
		res+=s[i];
		res%=mod;
	}
	return res;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	LL w[200005];
	LL pos[200005];
	for(int i=1;i<=n;i++)
		scanf("%lld",&pos[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
		add(i,w[i]);
		add1(s1,i,w[i]*pos[i]%mod);
		add1(s2,i,w[i]*(1000000005-pos[i])%mod);
		add1(s3,i,w[i]*i%mod);
		add1(s4,i,w[i]*(n+1-i)%mod);
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x>0){
			int mid=query(x,y);
			//printf("%d\n",mid);
			int l=x,r=y;
			LL ret1=query1(s1,r)-query1(s1,mid)-(query1(S,r)-query1(S,mid))%mod*pos[mid]%mod;
			LL ret2=query1(s2,mid-1)-query1(s2,l-1)-(query1(S,mid-1)-query1(S,l-1))%mod*(1000000005-pos[mid])%mod;
			ret1-=query1(s3,r)-query1(s3,mid)-mid*(query1(S,r)-query1(S,mid));
			ret2-=query1(s4,mid-1)-query1(s4,l-1)-(query1(S,mid-1)-query1(S,l-1))*(n+1-mid)%mod;
			ret1=(ret1%mod+mod)%mod;
			ret2=(ret2%mod+mod)%mod;
			printf("%lld\n",(ret1+ret2)%mod);
		}
		else{
			x=-x;
			add(x,y-w[x]);
			add1(s1,x,(y-w[x])*pos[x]%mod);
			add1(s2,x,(y-w[x])*(1000000005-pos[x])%mod);
			add1(s3,x,(y-w[x])*x%mod);
			add1(s4,x,(y-w[x])*(n+1-x)%mod);
			w[x]=y;
		}
	}
}