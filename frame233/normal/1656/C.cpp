#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int a[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	bool f0=0,f1=0;for(int i=1;i<=n;++i)f0|=a[i]==0,f1|=a[i]==1;
	if(f0&&f1)return puts("NO"),void();
	if(!f1)return puts("YES"),void();
	std::map<int,int> mp;for(int i=1;i<=n;++i)mp[a[i]]=1;
	for(int i=1;i<=n;++i)if(mp[a[i]-1])return puts("NO"),void();
	puts("YES");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}