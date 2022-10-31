#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N];
void MAIN(){
	int n,k;read(n,k);
	std::map<int,int> mp;
	for(int i=1;i<=n;++i)read(a[i]),++mp[a[i]];
	for(int i=1;i<=n;++i){
		if(mp.count(a[i]-k)){
			return puts("YES"),void();
		}
	}
	puts("NO");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}