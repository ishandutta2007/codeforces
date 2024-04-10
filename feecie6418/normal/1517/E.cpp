#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,v[400005],ans=0,c[105],p[105],cnt=0,cc[400005];
ll s[400005],s2[400005],A[400005],B[400005],T[400005];
void BF(){
	ans=0;
	for(int i=0;i<(1<<n);i++){
		int a=0,b=0;
		for(int j=1;j<=n;j++)if(i&(1<<j-1))c[++a]=j;else p[++b]=j;
		bool flag=1;
		for(int i=2;i<a;i++)if(c[i]-c[i-1]>c[i+1]-c[i])flag=0;
		for(int i=2;i<b;i++)if(p[i]-p[i-1]<p[i+1]-p[i])flag=0;
		if(flag){
			ll s1=0,s2=0;
			for(int i=1;i<=a;i++)s1+=v[c[i]];
			for(int i=1;i<=b;i++)s2+=v[p[i]];
			if(s1<s2)ans++;
		}
	}
	cout<<ans<<'\n';
}
void U(int x){
	while(x<=cnt)cc[x]++,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r=(r+cc[x])%mod,x-=x&-x;
	return r;
}
int id(ll x){
	return lower_bound(T+1,T+cnt+1,x)-T;
}
void Find(ll X){
	//A[i]+B[j]<=X,j-i=2k
	cnt=0;
	for(int i=n;i>=1;i--)T[++cnt]=X-A[i],T[++cnt]=B[i];
//	if(A[1]+B[1]>X)exit(1);
//	if(A[1]+B[3]>X)exit(2);
//	if(A[1]+B[5]>X)exit(3);
//	if(A[2]+B[4]>X)exit(4);
	sort(T+1,T+cnt+1);
	for(int i=1;i<=cnt;i++)cc[i]=0;
	for(int i=n;i>=1;i-=2)ans=(ans+Q(id(X-A[i])))%mod,U(id(B[i]));//,cout<<i<<' '<<A[3]+B[3]<<' '<<X<<'\n';
	//cout<<ans<<'\n';
	for(int i=1;i<=cnt;i++)cc[i]=0;
	for(int i=n-1;i>=1;i-=2)ans=(ans+Q(id(X-A[i])))%mod,U(id(B[i]));
}
void Solve4(){
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+v[i];
		s2[i]=s2[max(i-2,0)]+v[i];
		A[i]=s[i]+s2[i]-s2[i-1],B[i]=-s2[i]+s[i]+s2[i-1];
	}
	Find(s[n]+2*s[1]-1);//PP
	ans=(ans+1)%mod;//P 
	Find(s[n]-1);//CP
	for(int i=2;i<=n;i+=2)if(s2[i-1]<s[n]-s2[i-1])ans=(ans+1)%mod;
	B[n]=1e18;
	Find(s[n-1]-v[n]+2*s[1]-1);//PC
	for(int i=1;i<n;i++)if(s[i]>s[n]-s[i])ans=(ans+1)%mod;
	//cout<<ans<<'\n';
	Find(s[n-1]-v[n]-1);//CC
	for(int i=2;i<n;i+=2)if(s2[i-1]+v[n]<s[n-1]-s2[i-1])ans=(ans+1)%mod;
}
void SolvePC(){
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+v[i];
		s2[i]=s2[max(i-2,0)]+v[i];
		A[i]=s[i]+s2[i]-s2[i-1],B[i]=-s2[i]+s[i]+s2[i-1];
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	if(n<=3)return BF();
	ans=0,Solve4(),printf("%d\n",ans);
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}