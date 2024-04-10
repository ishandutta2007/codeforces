#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
char s[N];int cnt[26];
void MAIN(){
	scanf("%s",s+1);int n=strlen(s+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)++cnt[s[i]-'a'];
	for(int i=1;i<=n;++i){
		if(cnt[s[i]-'a']==1)return printf("%s\n",s+i),void();
		--cnt[s[i]-'a'];
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}