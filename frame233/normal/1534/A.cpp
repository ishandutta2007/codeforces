#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}
const int N=55;
char s[N][N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read_str(s[i]+1);
	for(int c=0;c<2;++c){
		bool flag=true;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
			int col=((i+j)&1)^c;
			if(col==0&&s[i][j]=='W')flag=false;
			if(col==1&&s[i][j]=='R')flag=false;
		}
		if(flag){
			puts("YES");
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)printf("%c",((i+j)&1)^c?'W':'R');
				printf("\n");
			}
			return;
		}
	}
	puts("NO");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}