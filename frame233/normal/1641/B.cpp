#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;typedef std::pair<int,int> pi;
int a[N];
void MAIN(){
	int n;read(n);std::map<int,int> mp;
	for(int i=1;i<=n;++i)read(a[i]),++mp[a[i]];
	for(auto it:mp)if(it.second%2)return puts("-1"),void();
	std::vector<pi> ans;std::vector<int> res;
	for(int i=n;i>=1;){
		int p=-1;for(int j=i-1;j>=1;--j)if(a[j]==a[i]){p=j;break;}
		int cur=p-1;
		int c=1;for(int j=i-1;j>p;--j)ans.pb({cur,a[j]}),++cur,++c;
		for(int j=p;j+1<i;++j)a[j]=a[j+1];
		std::reverse(a+p,a+i-1),res.pb(c*2),i-=2;
	}
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
	std::reverse(res.begin(),res.end());
	printf("%d\n",SZ(res));
	for(auto it:res)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}