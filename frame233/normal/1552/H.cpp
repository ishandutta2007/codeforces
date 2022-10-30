#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
int ask(int d){
	printf("? %d\n",200*(200/d));
	for(int i=d;i<=200;i+=d){
		for(int j=1;j<=200;++j)printf("%d %d ",i,j);
	}
	printf("\n"),fflush(stdout);
	int x;read(x);return x;
}
int main(){
	int l=1,r=7,mid;
	int f1=ask(1),res=8,ans=0;
	while(l<=r){
		mid=(l+r)>>1;int tmp=ask(1<<mid);
		if(tmp*(1<<mid)!=f1)res=mid,ans=tmp,r=mid-1;else l=mid+1;
	}
	int h=abs(ans*2-f1/(1<<(res-1))),w=f1/h;
	printf("! %d\n",(h+w-2)*2),fflush(stdout);
	return 0;
}