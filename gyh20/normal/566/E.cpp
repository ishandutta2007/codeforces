#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
bitset<1002>B[1002],tmp,G[1002];
int n,m,a[1002][1002],len[1002],cnt,fa[1002],num,dep[1002],s[1002];
int main(){
	n=read();
	re bool ia=1;
	for(re int i=1;i<=n;++i){
		len[i]=read();G[i][i]=1;
		ia&=(len[i]==n);
		for(re int j=1;j<=len[i];++j)B[i][a[i][j]=read()]=1;
	}
	if(ia){
		for(re int i=2;i<=n;++i)printnum(1,' '),printnum(i,'\n');
		return pc('o',1),0;
	}
	for(re int i=1;i<=n;++i)
		for(re int j=i+1;j<=n;++j){
			tmp=B[i]&B[j];
			if(tmp.count()==2){
				re int x=tmp._Find_first(),y=tmp._Find_next(x);
				if(G[x][y])continue;
				G[x][y]=G[y][x]=1,s[x]=s[y]=1;
				printnum(x,' '),printnum(y,'\n');
			}
		}len[0]=1e9;
	for(re int i=1;i<=n;++i){
		if(!s[i]){
			re int pos=0;
			for(re int j=1;j<=n;++j)if(B[j][i]&&len[j]<len[pos])tmp=B[j],pos=j;
			for(re int j=1;j<=n;++j)if(!s[j]&&j>=i)tmp[j]=0;else if(!s[j]&&tmp[j])fa[i]=fa[j];
			if(!fa[i])for(re int j=1;j<=len[pos];++j)if(s[a[pos][j]])if(G[a[pos][j]]==tmp)fa[i]=a[pos][j];
			G[i][fa[i]]=G[fa[i]][i]=1;
			printnum(i,' '),printnum(fa[i],'\n');
		}
	}
	pc('o',1);
}