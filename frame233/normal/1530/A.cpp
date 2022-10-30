#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
char s[15];
int main(){
	int _;read(_);
	while(_--){
		scanf("%s",s);
		int len=strlen(s);
		printf("%c\n",*std::max_element(s,s+len));
	}
	return 0;
}