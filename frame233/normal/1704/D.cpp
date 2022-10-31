#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;typedef __int128 LL;
void MAIN(){
	int n,m;read(n,m);
	LL mn=1e30,mx=0;int p=-1;
	for(int i=1;i<=n;++i){
		LL tot=0;
		for(int j=1,x;j<=m;++j){
			read(x),tot+=1LL*x*j;
		}
		if(tot<mn)mn=tot;
		if(tot>mx)mx=tot,p=i;
	}
	printf("%d %lld\n",p,(ll)(mx-mn));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}