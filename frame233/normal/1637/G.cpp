#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef std::pair<int,int> pi;std::vector<pi> ans;std::multiset<int> S;
void apply(int x,int y){
	S.erase(S.find(x)),S.erase(S.find(y));
	S.insert(x+y),S.insert(x>y?x-y:y-x),ans.pb({x,y});
}
void solve(int n,int t){
	if(n<=2)return;
	int q=0;while((1<<(q+1))<=n)++q;
	if((1<<q)==n)solve(n-1,t);
	else{
		for(int i=1;i<=n-(1<<q);++i)apply(((1<<q)-i)*t,((1<<q)+i)*t);
		solve((1<<q)-(n-(1<<q))-1,t),solve(n-(1<<q),t*2);
	}
}
void MAIN(){
	int n;read(n);
	if(n==2)return puts("-1"),void();
	S.clear(),ans.clear();for(int i=1;i<=n;++i)S.insert(i);
	solve(n,1);int last=-1;
	for(auto it:S){
		if(it==last){apply(it,last);break;}
		last=it;
	}
	int c=0;while(*S.begin()==0)S.erase(S.begin()),++c;
	S.insert(0);while(*++S.begin()!=*--S.end()){int x=*++S.begin();apply(0,x),apply(x,x);}
	for(int i=1;i<c;++i)S.insert(0);
	for(int i=1;i<=c;++i)apply(0,*--S.end());
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}