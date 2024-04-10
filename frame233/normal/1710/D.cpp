#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;typedef std::pair<int,int> pi;
struct node{int l,r;inline bool operator < (const node &o)const{return r-l<o.r-o.l;}}a[N*N/2];
char s[N];int fa[N],vec[N],vp;bool mark[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<pi> ans;void link(int x,int y){fa[find(x)]=find(y),ans.pb({x,y});}
void MAIN(){
	int n;read(n);int pos=0;
	for(int i=1;i<=n;++i){
		scanf("%s",s+i);
		for(int j=i;j<=n;++j)if(s[j]=='1')a[++pos]={i,j};
	}
	std::sort(a+1,a+pos+1),ans.clear();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=pos;++i){
		int x=find(a[i].l),y=find(a[i].r);
		if(x!=y){
			memset(mark,0,sizeof(mark)),mark[x]=mark[y]=1,vp=0;
			for(int j=a[i].l;j<=a[i].r;++j){
				int tmp=find(j);
				if(!mark[tmp])mark[tmp]=1,vec[++vp]=j;
			}
			link(a[i].l,a[i].r);
			for(int last=a[i].l,j=2;j<=vp;j+=2)link(last,vec[j]),last=vec[j];
			for(int last=a[i].r,j=1;j<=vp;j+=2)link(last,vec[j]),last=vec[j];
		}
	}
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}