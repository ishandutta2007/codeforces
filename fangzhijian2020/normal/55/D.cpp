#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=2520;
int T;long long l,r,f[20][2525][50],p[2525],t[50],lcm[2525][10],Mod[25250];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int cnt,Num[20];
void divide(long long x){
	cnt=0;
	while(x){
		Num[++cnt]=x%10;x/=10;
	}
}
long long dfs(int deep,int sum,int num,int opt){
	if(!opt&&f[deep][sum][num]!=-1)return f[deep][sum][num];
	if(deep==0){if(sum%t[num]==0)return 1;return 0;}
	long long ans=0;int Max=opt?Num[deep]:9;
	ans=dfs(deep-1,Mod[(sum<<3)+(sum<<1)],num,opt&Num[deep]==0);
	for(int i=1;i<=Max;++i){
		ans+=dfs(deep-1,Mod[(sum<<3)+(sum<<1)+i],p[lcm[num][i]],opt&Num[deep]==i);
	}
	if(!opt)f[deep][sum][num]=ans;return ans;
}
long long solve(long long x){
	if(!x)return 1;divide(x);
	return dfs(cnt,0,1,1);
}
int main(){
	scanf("%d",&T);++T;memset(f,-1,sizeof(f));
	int num=0;
	for(int i=1;i<=mod;++i){
		if(mod%i==0){
			t[++num]=i;p[i]=num;
			for(int j=1;j<=9;++j){
				lcm[num][j]=i/gcd(i,j)*j;
			}
		}
	}
	for(int i=1;i<=25210;++i)Mod[i]=i%mod;
	while(--T){
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}