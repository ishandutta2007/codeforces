#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
bool check(int x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
void MAIN(){
	int n;read(n);
	std::vector<int> v;int ban=0;
	int s=0;for(int i=1,x;i<=n;++i)read(x),s+=x,v.pb(x);
	if(check(s))for(int i=0;i<SZ(v);++i)if(v[i]%2){ban=i+1;break;}
	printf("%d\n",n-(!!ban));
	for(int i=1;i<=n;++i)if(i!=ban)printf("%d ",i);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}