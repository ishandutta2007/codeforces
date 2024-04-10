#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int inf=0x3f3f3f3f;
typedef long long ll;
std::unordered_map<ll,int> mp;
int n,m;
inline int ask(int x,int y){
	if(auto it=mp.find(1000000LL*x+y);it!=mp.end())return it->second;
	printf("? %d %d\n",x,y),fflush(stdout);
	int o;read(o);return mp[1000000LL*x+y]=o;
}
std::vector<int> solve(const std::vector<int> &X,const std::vector<int> &Y){
	if(SZ(X)==1){
		int mn=inf,pos=0;
		for(int i=0;i<SZ(Y);++i){
			int val=ask(X[0],Y[i]);
			if(val<mn)mn=val,pos=i;
		}
		return {pos};
	}
	if(SZ(X)>=SZ(Y)){
		std::vector<int> A;
		for(int i=1;i<SZ(X);i+=2)A.pb(X[i]);
		std::vector<int> L=solve(A,Y),ans;
		L.pb(SZ(Y)-1);
		for(int i=0,p=0;i<SZ(X);++i){
			if(i&1)ans.pb(L[p++]);
			else{
				int mn=inf,pos=0;
				for(int j=p?L[p-1]:0;j<=L[p];++j){
					int val=ask(X[i],Y[j]);
					if(val<mn)mn=val,pos=j;
				}
				ans.pb(pos);
			}
		}
		return ans;
	}
	else{
		std::vector<int> _Y={Y[0]};
		for(int i=1;i<SZ(Y);++i){
			while(!_Y.empty()){
				int a=ask(X[SZ(_Y)-1],_Y.back()),b=ask(X[SZ(_Y)-1],Y[i]);
				if(a>=b)_Y.pop_back();
				else break;
			}
			if(SZ(X)!=SZ(_Y))_Y.pb(Y[i]);
		}
		std::vector<int> L=solve(X,_Y),ans(SZ(L));
		for(int i=0,p=0;i<SZ(ans);++i){
			while(p<SZ(Y)&&Y[p]<_Y[L[i]])++p;
			ans[i]=p;
		}
		return ans;
	}
}
int main(){
	read(n,m);
	std::vector<int> X(n);std::iota(X.begin(),X.end(),1);
	std::vector<int> Y(m);std::iota(Y.begin(),Y.end(),1);
	std::vector<int> L=solve(X,Y);
	int mn=inf;for(int i=0;i<n;++i)mn=std::min(mn,ask(i+1,L[i]+1));
	printf("! %d\n",mn),fflush(stdout);
	return 0;
}