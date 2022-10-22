//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=1005,M=1e6+5;
char s[N][N],t[M];int n,k,l,bg,pos;
int main(){
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",t+1);
	sort(t+1,t+1+n*l);
	bg=1,pos=1;
	fp(j,1,l){
		fp(i,bg,k)s[i][j]=t[pos++];
		fd(i,k,bg+1)if(s[i][j]!=s[i-1][j]){bg=i;break;}
	}
	fp(i,1,n)fp(j,1,l)if(!s[i][j])s[i][j]=t[pos++];
	fp(i,1,n)printf("%s\n",s[i]+1);
	return 0;
}