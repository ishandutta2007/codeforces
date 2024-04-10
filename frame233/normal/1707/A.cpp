#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int a[N];char ans[N];
void MAIN(){
	int n,q;read(n,q);ans[n+1]=0;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=n,cur=0;i>=1;--i){
		if(a[i]<=cur)ans[i]='1';
		else if(cur<q)++cur,ans[i]='1';
		else ans[i]='0';
	}
	printf("%s\n",ans+1);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}