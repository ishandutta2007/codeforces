#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,f[100002][2],ans1,ans2,ans3,ans4,ans5,ans6;
char s[202];
int main(){
	n=read();ans4=1;
	for(re int i=1;i<=n;++i){
		scanf("%s",s+1);
		ans1+=s[1]=='W',ans1+=s[2]=='W';
		ans2+=s[1]=='B',ans2+=s[2]=='B';
		ans3+=s[1]=='?',ans3+=s[2]=='?';
		re int c=0;
		if(s[1]!='W'&&s[2]!='B')++c,++ans5;
		if(s[1]!='B'&&s[2]!='W')++c,++ans6;
		ans4=1ll*ans4*c%M;
	}
	re int s=1;
	for(re int i=1;i<=ans3;++i)s=1ll*s*i%M;
	re int x=(abs(ans1-ans2)+ans3)>>1;
	if(x>ans3){
		puts("0");
		return 0;
	}
	for(re int i=1;i<=x;++i)s=1ll*s*ksm(i,M-2)%M;
	for(re int i=1;i<=ans3-x;++i)s=1ll*s*ksm(i,M-2)%M;
	add(s,M-ans4);
	if(ans5==n)add(s,1);
	if(ans6==n)add(s,1);
	printf("%d",s);
}