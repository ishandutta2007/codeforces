#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=100005;
int a[N],s[N],f[N];
void MAIN(){
	int n;read(n);std::map<int,int> mp;
	for(int i=1;i<=n;++i)read(a[i]),s[i]=s[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];auto it=mp.find(s[i]);
		if(it!=mp.end())f[i]=std::max(f[i],it->second+1);
		chmax(mp[s[i]],f[i]);
	}
	printf("%d\n",n-f[n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}