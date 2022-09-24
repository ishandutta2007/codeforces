#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int m,neg1[25]={0,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
long long poW2[25]={0,1};
long long x[20],a[20],ans=0,n;
inline long long Gcd(long long x,long long y){
	return x%y?Gcd(y,x%y):y;
}
inline long long Lcm(long long x,long long y){
	long long t=Gcd(x,y);
	if(log(x)+log(y)-log(t)>log(n)+1e-6)return -1;
	if(x/t*y>n)return -1;
	return x/t*y;
}
void DFS(int now,int left,int lastt,int all){
	//cout<<now<<' '<<left<<' '<<all<<endl;
	if(!left){
		long long lcc=1;
		for(int i=1;i<=all;i++){
			lcc=Lcm(lcc,a[i]);
			if(lcc==-1)return ;
		}
		ans+=n/lcc*neg1[all];
		//cout<<all<<' '<<ans<<endl;
		return ;
	}
	for(int i=lastt+1;i<=m-left+1;i++){
		a[now]=x[i];
		DFS(now+1,left-1,i,all);
	}
}
int main(){
	//freopen("light.in","r",stdin);
	//freopen("light.out","w",stdout);
	for(int i=2;i<=17;i++)poW2[i]=poW2[i-1]*2;
	scanf("%lld",&n);
	m=9;
	//printf("%lf\n",pow(2.718281828,log(1e18)+1e-6));
	for(int i=1;i<=m;i++)x[i]=i+1;
	for(int i=1;i<=m;i++)DFS(1,i,0,i);
	printf("%lld\n",n-ans);
	return 0;
}