#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;
int ask(const std::vector<int> &o){
	printf("? ");
	for(auto it:o)printf("%d ",it);
	printf("\n"),fflush(stdout);
	int x;read(x);
	return x;
}
int dis[N],_q[N],_l,_r,a[N],pre[N];
int main(){
	int n,k;read(n,k);
	memset(dis,-1,sizeof(dis));
	_q[_l=_r=1]=0;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=0;i<=k&&i<=x;++i)if(k-i<=n-x){
			int to=x+k-2*i;
			if(to<=n&&dis[to]==-1)dis[to]=dis[x]=1,_q[++_r]=to,pre[to]=x;
		}
	}
	if(dis[n]==-1)return puts("-1"),fflush(stdout),0;
	int pos=0,ans=0;
	for(int i=n;i;i=pre[i])a[++pos]=i;
	std::vector<int> cur,rest(n);
	std::iota(rest.begin(),rest.end(),1);
	for(int i=pos;i>=1;--i){
		int qwq=a[i]-a[i+1],qaq=(k-qwq)/2;
		std::vector<int> o,A,B;
		for(int j=0;j<qaq;++j)o.pb(cur.back()),A.pb(cur.back()),cur.pop_back();
		for(int j=qaq;j<k;++j)o.pb(rest.back()),B.pb(rest.back()),rest.pop_back();
		ans^=ask(o);
		for(auto it:A)rest.pb(it);
		for(auto it:B)cur.pb(it);
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}