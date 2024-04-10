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
const int N=100005;
char s[N];bool is[2];
void MAIN(){
	int n=read_str(s+1);
	memset(is,0,sizeof(is));
	for(int i=1;i<=n;++i)is[s[i]-'0']=true;
	if(!is[0])return puts("0"),void();
	if(!is[1])return puts("1"),void();
	int l=-1,r=-1;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			l=i;break;
		}
	}
	for(int i=n;i>=1;--i){
		if(s[i]=='0'){
			r=i;break;
		}
	}
	bool flag=true;
	for(int i=l;i<=r;++i)flag&=s[i]=='0';
	puts(flag?"1":"2");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}