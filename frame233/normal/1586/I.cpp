#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;
int col[N][N],tag[N][N],val[N];char s[N];
int main(){
	int n;read(n);
	if(n%2)return puts("NONE"),0;
	int cur=0;
	for(int i=1;i<=n;i+=2){
		#define DO col[x][y]=cur,tag[x][y]=t^=1
		++cur;int x=1,y=i,t=0;
		t^=1,DO;while(y>1)++x,--y,DO;
		++x,t^=1,DO;while(x<n)++x,++y,DO;
		++y,t^=1,DO;while(y<n)--x,++y,DO;
		--x,t^=1,DO;while(x>1)--x,--y,DO;
	}
	memset(val,-1,sizeof(val));
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=n;++j){
			if(s[j]=='.')continue;
			int tmp=tag[i][j]^(s[j]=='G');
			if(val[col[i][j]]!=-1&&val[col[i][j]]!=tmp)return puts("NONE"),0;
			val[col[i][j]]=tmp;
		}
	}
	for(int i=1;i<=cur;++i)if(val[i]==-1)return puts("MULTIPLE"),0;
	puts("UNIQUE");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)putchar("SG"[val[col[i][j]]^tag[i][j]]);
		putchar('\n');
	}
	return 0;
}