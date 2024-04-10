#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[200002],t,ans;
char s[302][302];
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
inline int ck1(int x,int y){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='.')continue;
				else{
					if((i+j)%3==x&&s[i][j]=='X')++sum1;
					if((i+j)%3==y&&s[i][j]=='O')++sum2;
				}
		}
	}
	if(sum1+sum2<=ans/3){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='.')putchar('.');
				else{
					if((i+j)%3==x&&s[i][j]=='X')putchar('O');
					else if((i+j)%3==y&&s[i][j]=='O')putchar('X');
					else putchar(s[i][j]);
				}
			}
			puts("");
		}
		return 1;
	}
	return 0;
}
inline int ck2(int x,int y){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='.')continue;
				else{
					if((i-j+300000)%3==x&&s[i][j]=='X')++sum1;
					if((i-j+300000)%3==y&&s[i][j]=='O')++sum2;
				}
		}
	}
	if(sum1+sum2<=ans/3){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='.')putchar('.');
				else{
					if((i-j+300000)%3==x&&s[i][j]=='X')putchar('O');
					else if((i-j+300000)%3==y&&s[i][j]=='O')putchar('X');
					else putchar(s[i][j]);
				}
			}
			puts("");
		}
		return 1;
	}
	return 0;
}
int main(){
	t=read();
	while(t--){
		memset(s,0,sizeof(s));
		n=read();ans=0;
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]!='.')++ans;
			}
		}
		bool ia=0;
		for(int i=0;i<=2;++i){
			for(int j=0;j<=2;++j){
				if(i==j)continue;
				if(!ia)ia|=ck1(i,j);
				if(!ia)ia|=ck2(i,j);
			}
		}
	}
}