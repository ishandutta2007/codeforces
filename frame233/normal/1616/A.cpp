#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int n;read(n);std::set<int> S;
	for(int i=1,x;i<=n;++i){
		read(x);
		if(S.count(x))S.insert(-x);
		else S.insert(x);
	}
	printf("%d\n",SZ(S));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}