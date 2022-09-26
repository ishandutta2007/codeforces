#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 123
#define M 70030
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,s,dp[N][M],ans,mid;
struct Task{
	int a,b;
}p[N];
bool cmp1(Task x,Task y){
	return x.a<y.a;
}
bool cmp2(Task x,Task y){
	return x.a+x.b>y.a+y.b;
}
bool cmp3(Task x,Task y){
	return x.b>y.b;
}
int main(){
	n=read(),s=read();
	for(int i=1;i<=n;i++){
		p[i].a=read(),p[i].b=read();
	}
	sort(p+1,p+n+1,cmp3);
	mid=1;
	while(p[mid].b>=0&&mid<=n)++mid;
	sort(p+1,p+mid,cmp1);
	sort(p+mid,p+n+1,cmp2);
	memset(dp,~0x3f,sizeof(dp));
	dp[0][s]=0;
	for(int i=1;i<=n;i++){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		for(int j=60000;j>=p[i].a+p[i].b;j--){
			dp[i][j]=max(dp[i][j],dp[i-1][j-p[i].b]+1);
		}
	}
	for(int i=0;i<=60000;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}