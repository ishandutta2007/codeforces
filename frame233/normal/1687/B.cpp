#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;
int t[N],v[N];
inline int ask(const std::string &s){
	printf("? %s\n",s.c_str()),fflush(stdout);
	int x;read(x);return x;
}
int main(){
	int n,m;read(n,m);
	for(int i=0;i<m;++i){
		std::string s;s.resize(m);
		for(int j=0;j<m;++j)s[j]=i==j?'1':'0';
		v[i]=ask(s),t[i]=i;
	}
	std::sort(t,t+m,[&](int x,int y){return v[x]<v[y];});
	std::string s;s.resize(m);for(int i=0;i<m;++i)s[i]='0';
	int cur=0;
	for(int i=0;i<m;++i){
		s[t[i]]='1';int tmp=ask(s);
		if(tmp-cur<v[t[i]])s[t[i]]='0';else cur=tmp;
	}
	printf("! %d\n",cur),fflush(stdout);
	return 0;
}