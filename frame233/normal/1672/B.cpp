#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
char s[N];
void MAIN(){
	scanf("%s",s+1);int n=strlen(s+1);
	if(s[n]=='A')return puts("NO"),void();
	int c=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='A')++c;
		else if(--c<0)return puts("NO"),void();
	}
	puts("YES");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}