#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,INF=0x3f3f3f3f;
char opt[N];
priority_queue<int>q;
int n,top,a[N],sta[N];
V my_assert(int x){if(!x)cout<<"NO\n",exit(0);}
char GC(){
	char st[10];
	return scanf("%s",st),st[0];
}
V input(){
	scanf("%d",&n);
	FOR(i,1,n+n)if(opt[i]=GC(),opt[i]=='-')
		scanf("%d",a+i);
}
V init(){
	FOR(i,1,n+n)
		if(opt[i]=='+')sta[++top]=i;
		else my_assert(top),a[sta[top--]]=a[i];
}
V work(){
	FOR(i,1,n+n)
		if(opt[i]=='+')q.push(-a[i]);
		else my_assert(a[i]+q.top()==0),q.pop();
	cout<<"YES\n";
	FOR(i,1,n+n)if(opt[i]=='+')cout<<a[i]<<' ';
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}