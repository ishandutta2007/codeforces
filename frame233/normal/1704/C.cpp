#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int a[N],b[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=m;++i)read(a[i]);
	std::sort(a+1,a+m+1);int pos=0;
	for(int i=1;i<m;++i)b[++pos]=a[i+1]-a[i]-1;
	b[++pos]=n-a[m]+a[1]-1;std::sort(b+1,b+pos+1,std::greater<int>());
	int ans=0;
	for(int i=1;i<=pos;++i){
		if(b[i]==4*(i-1)+1)++ans;
		else ans+=std::max(0,b[i]-4*(i-1)-1);
	}
	printf("%d\n",n-ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}