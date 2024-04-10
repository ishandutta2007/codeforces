#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005,M=800;
int s[M+5],f[M+5];std::vector<int> v[N];
inline int calc(int x){return x*(x+1)/2;}
int main(){
	int n,k;read(n,k);
	for(int i=1,x,y;i<=k;++i){read(x,y);if(n-x+1<=M)v[y].push_back(n-x+1);}
	memset(f,63,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;++i){
		memset(s,0,sizeof(s));for(auto it:v[i])s[it]+=3;
		for(int j=1;j<=M;++j)s[j]+=s[j-1];
		int o=f[0];for(int j=0,pre=1e9;j<=M;++j)pre=std::min(pre,f[j]),f[j]=std::min(pre+calc(j)+2,f[j+1])-s[j];
		f[0]=std::min(f[0],o);
	}
	printf("%d\n",std::min(f[0],f[1])+3*k);
	return 0;
}