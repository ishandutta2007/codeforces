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

const int N=1005;
char s[N];
int a[N],b[N];
void MAIN(){
	int n,m;read(n,m);
	read_str(s+1);for(int i=1;i<=n;++i)a[i]=s[i]-48;
	m=std::min(n,m);
	a[n+1]=b[n+1]=0;
	for(int _=0;_<m;++_){
		for(int i=1;i<=n;++i){
			if(a[i]==0&&a[i-1]+a[i+1]==1)b[i]=1;
			else b[i]=a[i];
		}
		memcpy(a,b,(n+3)<<2);
	}
	for(int i=1;i<=n;++i)printf("%d",a[i]);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}