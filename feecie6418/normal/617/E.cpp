// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
struct read {
	char buf[2000005],*opt;
	read():opt(buf) {
		buf[fread(buf,1,sizeof buf,stdin)]=0;
	}
	template <typename _int>
	inline operator _int() {
		register _int res=0;
		while(*opt<48)++opt;
		while(*opt>32)res=(res<<1)+(res<<3)+(*opt++)-48;
		return res;
	}
} it;
char buffer[2000005];
int p1=-1;
const int p2=2000000;
inline void flush() {
	fwrite(buffer,1,p1+1,stdout),p1=-1;
}
inline void putc(const char &x){
	if(p1==p2)flush();
	buffer[++p1]=x;
}
void wrtn(long long x) {
	static char buf[15];
	static int len=-1;
	do {
		buf[++len]=x%10+48,x/=10;
	} while(x);
	while(len>=0){
		putc(buf[len]),--len;
	}
	putc('\n');
}
int n,s[100005],a[100005],bel[100005],cnt[1048580],m,k;
long long ans=0,anss[100005];
struct Query{
	int l,r,id;
	bool operator <(const Query yy) const {
		return bel[l]!=bel[yy.l]?bel[l]<bel[yy.l]:(bel[l]&1?r<yy.r:r>yy.r);
	}
}q[100005];
int main(){
	n=it,m=it,k=it;
//	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,c=sqrt(n);i<=n;i++){
		a[i]=it;
//		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		bel[i]=i/c+1;
	}
	for(int i=1;i<=m;i++){
		(q[i].l=it)-=1,q[i].r=it;
//		scanf("%d%d",&q[i].l,&q[i].r),q[i].l--;
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	register int nowl=1,nowr=0;
	for(int i=1;i<=m;i++){
		while(nowl<q[i].l){
			cnt[s[nowl]]--;
			ans-=cnt[s[nowl]^k];
			++nowl;
		}
		while(nowr>q[i].r){
			cnt[s[nowr]]--;
			ans-=cnt[s[nowr]^k];
			--nowr;
		}
		while(nowl>q[i].l){
			--nowl;
			ans+=cnt[s[nowl]^k];
			cnt[s[nowl]]++;
		}
		while(nowr<q[i].r){
			++nowr;
			ans+=cnt[s[nowr]^k];
			cnt[s[nowr]]++;
		}
		anss[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)wrtn(anss[i]);
	flush();
    return 0;
}