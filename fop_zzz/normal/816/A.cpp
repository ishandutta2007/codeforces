#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(ll &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
inline bool check(ll a,ll b){
	if(a%10==b/10&&b%10==a/10)return true; else return false;
}
int main(){
	ll s1,s2;
	scanf("%I64d:%I64d",&s1,&s2);
	ll ans=0; 
	while(!check(s1,s2)){
		ans++; s2++; if(s2==60){
			s2=0; s1++;
		}
		if(s1==24)s1=0;
	}
	writeln(ans);
}