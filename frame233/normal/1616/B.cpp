#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
char s[N];
std::string get(int k){
	std::string ans;for(int i=1;i<=k;++i)ans.pb(s[i]);
	for(int i=k;i>=1;--i)ans.pb(s[i]);
	return ans;
}
void MAIN(){
	int n;read(n);scanf("%s",s+1);
	int pos=1;while(pos<n&&s[pos+1]<=s[pos])++pos;
	std::string ans;
	for(int c=0;c<26;++c){
		for(int i=1;i<=pos;++i)if(s[i]-'a'==c){
			std::string cur=std::move(get(i));
			if(ans.empty()||cur<ans)ans=cur;
			break;
		}
		for(int i=pos;i>=1;--i)if(s[i]-'a'==c){
			std::string cur=std::move(get(i));
			if(ans.empty()||cur<ans)ans=cur;
			break;
		}
	}
	printf("%s\n",ans.c_str());
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}