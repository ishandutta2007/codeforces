#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
std::map<int,int> mp;
int ask(int w){
	auto it=mp.find(w);if(it!=mp.end())return it->second;
	printf("? %d\n",w),fflush(stdout);int x;read(x);return mp[w]=x;
}
int main(){
	mp[0]=0;int n;read(n);
	int l=0,r=2000*n+n,mid;
	while(l<r)mid=(l+r)>>1,ask(mid)==1?r=mid:l=mid+1;
	int s=l-n+1,ans=l;
	for(int h=2;h<=n;++h){
		while(ans>s){
			int tmp=(ans-1)/h;
			if(tmp*h>=s+n-h&&ask(tmp)==h)ans=tmp*h;
			else break;
		}
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}