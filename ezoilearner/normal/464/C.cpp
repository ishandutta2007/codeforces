#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int n;
#define Maxn 1000010
struct Q{
	int num,pos;
}q[Maxn];
struct Num{
	int len,sumv;
}num[10];
char ch[Maxn];
char str[Maxn];
char T[Maxn];
int cnt=0;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%s",ch+1);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		int len=strlen(str+1);
		q[i].num=str[1]-'0';
	    for(int j=4;j<=len;++j)T[++cnt]=str[j];
	    q[i].pos=q[i-1].pos+len-3;
	}
	for(int i=0;i<10;++i)num[i].len=1,num[i].sumv=i;
	for(int i=n;i>=1;--i){
		int Sumv=0,Len=0;
		for(int j=q[i].pos;j>=q[i-1].pos+1;--j){
			Sumv=(Sumv+1ll*num[T[j]-'0'].sumv*pow(10,Len)%Mod)%Mod;
			Len=(Len+num[T[j]-'0'].len)%(Mod-1);
		}
		num[q[i].num].sumv=Sumv;
		num[q[i].num].len=Len;
	}
	int len=strlen(ch+1);
	int Len=0,Ans=0;
	for(int i=len;i>=0;--i){
		Ans=(Ans+1ll*num[ch[i]-'0'].sumv*pow(10,Len)%Mod)%Mod;
		Len=(Len+num[ch[i]-'0'].len)%(Mod-1);
	}
	printf("%d\n",Ans);
	return 0;
}