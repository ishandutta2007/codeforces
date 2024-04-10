#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int a[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int p=n;while(p&&!a[p])--p;
	if(p==0)return puts("Yes"),void();
	if(a[1]<=0||a[p]>0)return puts("No"),void();
	++a[p],--a[1];
	ll tot=0;for(int i=n;i>=1;--i){tot+=a[i];if(tot>0)return puts("No"),void();}
	if(tot==0)puts("Yes");else puts("No");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}