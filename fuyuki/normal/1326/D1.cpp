#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e6+1,mod=998244353;
int T,n,m,len,L,R,pos,p[N];
char tmp[N],st[N];
V input(){
	scanf("%s",tmp+1),n=strlen(tmp+1);
}
V init(){
	L=1,R=n;
	while(L<=R&&tmp[L]==tmp[R])
		L++,R--;
}
V manacher(){
	int mid=0,l=0,r=0,maxn=0;
	FOR(i,1,len){
		p[i]=min(p[(mid<<1)-i],r-i);
		while(i>=p[i]&&i+p[i]<=len&&st[i-p[i]]==st[i+p[i]])
			p[i]++;
		if(p[i]+i>r)r=p[i]+i-1,mid=i;
		if(p[i]==i+1)pos=i,maxn=p[i];
		if(i+p[i]==len+1){
			if(p[i]>maxn)pos=i;
			return;
		}
	}
}
V work(){
	if(L>R)return void(cout<<tmp+1<<'\n');
	st[0]='#',len=0;
	FOR(i,L,R)st[++len]=tmp[i],st[++len]='#';
	FOR(i,1,len)p[i]=0;
	manacher();
	FOR(i,1,L-1)cout<<tmp[i];
	FOR(i,pos-p[pos]+1,pos+p[pos]-1)if(st[i]!='#')
		cout<<st[i];
	FOR(i,R+1,n)cout<<tmp[i];
	cout<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}