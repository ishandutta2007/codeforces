#include<cstdio>
#include<iostream>
using namespace std;
#define re register
#define I inline int
#define FOR(i,a,b) for(re int i=a;i<=b;i++)
const int N=2e5+10;
int n,ans,tag=1,val[N],cnt[N];
char st[N];
I gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	scanf("%d%s",&n,st+1);
	FOR(i,1,n-1)
		if(n%i==0){
			FOR(j,1,n)cnt[j%i]^=st[j]-'0';
			val[i]=1;
			FOR(j,0,i-1)val[i]&=!cnt[j],cnt[j]=0;
		}
	FOR(i,1,n-1)ans+=val[gcd(i,n)];
	FOR(i,1,n)tag&=st[i]=='0';
	cout<<ans+tag;
	return 0;
}
/*
3
110
*/