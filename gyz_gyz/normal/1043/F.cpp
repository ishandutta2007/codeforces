#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,tot,ans,fr[N],p[N],a[N],cl[N],s[N];
void ppr(){
	int x=a[1];if(x==1)return;
	rep(i,2,n){
		x=__gcd(a[i],x);
		if(x==1)return;
	}
	printf("-1\n");exit(0);
}
void sol(){int m=(1<<8)-1;
	rep(i,1,tot)cl[i]=rand()%8;
	rep(i,0,m)s[i]=n+1;
	rep(i,1,n){int x=a[i],y=0;
		for(;x>1;x/=p[fr[x]])y|=1<<cl[fr[x]];s[y]=1;
	}
	dep(i,m-1,0)rep(j,i+1,m)s[i&j]=min(s[i&j],s[i]+s[j]);
	ans=min(ans,s[0]);
}
int main(){
	srand(time(0));
	rep(i,2,300000){
		if(!fr[i])p[++tot]=i,fr[i]=tot;
		rep(j,1,tot){
			if(i*p[j]>300000)break;
			fr[i*p[j]]=j;
			if(!(i%p[j]))break;
		}
	}
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		for(a[i]=1;x>1;x/=p[fr[x]])
			if(a[i]%p[fr[x]])a[i]*=p[fr[x]];
	}
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
	ppr();ans=n+1;
	while(clock()<2800)sol();
	printf("%d\n",ans);
}