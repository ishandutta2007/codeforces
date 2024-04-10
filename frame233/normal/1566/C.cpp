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
char s[N],t[N];
void MAIN(){
	int n;read(n);read_str(s+1),read_str(t+1);
	int ans=0,last=-1;
	for(int i=1;i<=n;i++){
		if(s[i]-48+t[i]-48==1)ans+=!last,last=-1,ans+=2;
		else if(s[i]-48+t[i]-48==0){
			if(last==0)++ans;
			else if(last==1)ans+=2,last=-1;
			else last=0;
		}
		else{if(last==0)ans+=2,last=-1;else last=1;}
	}
	printf("%d\n",ans+(!last));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}