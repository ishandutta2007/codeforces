#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,inf=0x3f3f3f3f,INF=0x7fffffff;
int l[N],r[N],c[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(l[i],r[i],c[i]);
	int mn=1e9,mx=0,vn=inf,vx=inf,ml=0,v=INF;
	for(int i=1;i<=n;++i){
		if(l[i]<mn)mn=l[i],vn=c[i];else if(l[i]==mn&&c[i]<vn)vn=c[i];
		if(r[i]>mx)mx=r[i],vx=c[i];else if(r[i]==mx&&c[i]<vx)vx=c[i];
		if(r[i]-l[i]+1>ml)ml=r[i]-l[i]+1,v=c[i];else if(r[i]-l[i]+1==ml&&c[i]<v)v=c[i];
		if(ml==mx-mn+1)printf("%d\n",std::min(v,vn+vx));
		else printf("%d\n",vn+vx);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}