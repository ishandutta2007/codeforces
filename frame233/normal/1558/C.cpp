#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2025;
int a[N];
void MAIN(){
	int n;read(n);
	bool flag=1;for(int i=1;i<=n;++i)read(a[i]),flag&=(a[i]^i)%2==0;
	if(!flag)return puts("-1"),void();
	std::vector<int> ans;
	for(int i=n;i>1;i-=2){
		int podd=std::find(a+1,a+i+1,i)-a;
		ans.pb(podd),std::reverse(a+1,a+podd+1);
		int peven=std::find(a+1,a+i+1,i-1)-a;
		ans.pb(peven-1),std::reverse(a+1,a+peven);
		ans.pb(peven+1),std::reverse(a+1,a+peven+2);
		ans.pb(3),std::reverse(a+1,a+4);
		ans.pb(i),std::reverse(a+1,a+i+1);
	}
	printf("%d\n",SZ(ans));
	for(auto it:ans)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}