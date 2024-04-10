#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e6+5;
int n,tot,m,ans;
int fa[N],siz[N],tag[N];
char tmp[N];
V input(){
	scanf("%d",&n),ans=n;
}
V init(){FOR(i,1,26)fa[i]=i;tot=26;}
I find(rnt x){return x==fa[x]?x:fa[x]=find(fa[x]);}
V work(){
	FOR(i,1,n){
		scanf("%s",tmp+1);rnt len=strlen(tmp+1);
		fa[++tot]=tot;
		FOR(i,1,len){
			rnt x=find(tmp[i]-'a'+1),y=find(tot);
			tag[x]=1;
			if(y!=x)
				fa[y]=x,ans--;
		}
	}
	FOR(i,1,26)ans+=tag[i];
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}