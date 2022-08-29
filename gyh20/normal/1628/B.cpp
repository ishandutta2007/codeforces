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
int t,n,m,a[1000002],ans,A,B,ck[202],len[1000002];
char s[1000002][6];
map<string,int>V;
int main(){
	t=read();
	while(t--){
		n=read();V.clear();
		for(re int i=1;i<=n;++i)memset(s[i],0,sizeof(s[i])),scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
		bool ia=0;
		memset(ck,0,sizeof(ck));
		for(re int i=1;i<=n;++i){
			re int o=1;
			for(re int j=1;j<=len[i];++j)o&=s[i][j]==s[i][len[i]-j+1];
			ia|=o;
			if(len[i]==1&&ck[s[i][1]])ia=1;
			if(len[i]<=2||s[i][2]==s[i][3])ck[s[i][1]]=1;
		}
		memset(ck,0,sizeof(ck));
		for(re int i=n;i;--i){
			if(len[i]==1&&ck[s[i][1]])ia=1;
			if(len[i]<=2||s[i][1]==s[i][2])ck[s[i][len[i]]]=1;
		}
		for(re int i=1;i<=n;++i){
			reverse(s[i]+1,s[i]+len[i]+1);
			ia|=V[s[i]+1];
			reverse(s[i]+1,s[i]+len[i]+1);
			re int o=s[i][3];s[i][3]=0;
			++V[s[i]+1];
			s[i][3]=o;
			++V[s[i]+1];
		}
		V.clear();
		for(re int i=n;i;--i){
			reverse(s[i]+1,s[i]+len[i]+1);
			ia|=V[s[i]+1];
			reverse(s[i]+1,s[i]+len[i]+1);
			++V[s[i]+1];
			++V[s[i]+(len[i]==3?2:1)];
		}
		V.clear();
		puts(ia?"YES":"NO"); 
	}
}