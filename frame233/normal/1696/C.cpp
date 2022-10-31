#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=50005;typedef long long ll;
struct node{ll val,cnt;};
void MAIN(){
	int n,m;read(n,m);std::vector<node> vec;
	for(int i=1,x;i<=n;++i){
		read(x);int v=x,c=1;
		while(v%m==0)c*=m,v/=m;
		if(!vec.empty()&&v==vec.back().val)vec.back().cnt+=c;
		else vec.pb({v,c});
	}
	int k;read(k);int p=0;
	for(int i=1,x;i<=k;++i){
		read(x);int v=x,c=1;
		while(v%m==0)c*=m,v/=m;
		if(p<SZ(vec)&&vec[p].val==v&&vec[p].cnt>=c){
			vec[p].cnt-=c;if(!vec[p].cnt)++p;
		}
		else{
			for(int j=i+1;j<=k;++j)read(x);
			return puts("No"),void();
		}
	}
	if(p!=SZ(vec))puts("No");else puts("Yes");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}