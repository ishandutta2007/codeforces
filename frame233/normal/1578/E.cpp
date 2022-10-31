#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
const int N=2005;typedef std::pair<int,int> pi;
char s[N],t[N],tmp[N];int n,k,c,p[N];
bool cmp(char *a,char *b){for(int i=1;i<=n;++i)if(a[i]!=b[i])return a[i]<b[i];return 0;}
std::vector<pi> solve(char *s){
	std::vector<pi> ans;int pos;
	auto apply=[&](int l,int r){std::reverse(s+l,s+r+1),ans.pb({l,r});};
	auto init=[&](){pos=0;for(int i=1;i<=n;++i)if(s[i]=='1')p[++pos]=i;p[++pos]=n+1;};
	if(k==c){
		for(int i=n;i>=1;--i)if(s[i]=='1'){apply(1,i);break;}
		memcpy(tmp,s,n+3);
		for(int i=n;i>=1;--i)if(s[i]=='1'){
			std::reverse(tmp+1,tmp+i+1);
			if(cmp(tmp,s))apply(1,i);
			break;
		}
		return ans;
	}
	init();
	for(int i=pos;i>k+2;--i)apply(p[i-k],p[i]-1),init();
	if(k%2)for(int i=1;i<=k+1;++i)apply(p[1],p[k+1]-1),init(),apply(p[1]+1,p[k+2]-1),init();
	else for(int i=1;i<=k/2;++i)apply(p[1],p[k+1]-1),init(),apply(p[1]+1,p[k+1]),init();
	return ans;
}
void MAIN(){
	scanf("%d%d%s%s",&n,&k,s+1,t+1);
	bool flag=1;for(int i=1;i<=n;++i)flag&=s[i]==t[i];
	if(flag)return puts("0"),void();
	c=0;int c2=0;for(int i=1;i<=n;++i)c+=s[i]=='1',c2+=t[i]=='1';
	if(c!=c2||!k||k>c)return puts("-1"),void();
	std::vector<pi> a=solve(s),b=solve(t);
	for(int i=1;i<=n;++i)if(s[i]!=t[i])return puts("-1"),void();
	std::reverse(b.begin(),b.end()),a.insert(a.end(),b.begin(),b.end());
	printf("%d\n",SZ(a));
	for(auto [x,y]:a)printf("%d %d\n",x,y);
}
int main(){
	int _;scanf("%d",&_);
	while(_--)MAIN();
	return 0;
}