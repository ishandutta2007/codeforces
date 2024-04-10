#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
const int INF=0x3f3f3f3f;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("I.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
#else
int readint(){
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++);
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return val;
}
#endif
char readchar(){
	for(;isspace(buf[bufpos]);bufpos++);
	return buf[bufpos++];
}
int readstr(char* s){
	int cur=0;
	for(;isspace(buf[bufpos]);bufpos++);
	for(;!isspace(buf[bufpos]);bufpos++)
		s[cur++]=buf[bufpos];
	s[cur]='\0';
	return cur;
}
const int maxn=300002;
int a[maxn],f[maxn];
int first[maxn],nxt[maxn];
bool qwq[maxn];
multiset<int> s;
void add(int x,int y){
	nxt[y]=first[x];
	first[x]=y;
}
int main(){
	init();
	int n=readint(),m=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	sort(a+1,a+n+1);
	f[0]=0;
	qwq[0]=true;
	int now=a[1];
	for(int i=1;i<m;i++)
		f[i]=INF;
	s.insert(INF);
	for(int i=m;i<=n;i++){
		if (qwq[i-m])
			now=max(now,a[i-m+1]);
		else s.insert(f[i-m]);
		for(int j=first[i];j;j=nxt[j]){
			qwq[j]=true;
			if (j<=i-m)
				s.erase(s.find(f[j])),now=max(now,a[j+1]);
		}
		f[i]=min(a[i]-now,*s.begin());
		int w=upper_bound(a+1,a+n+1,f[i]+a[i+1])-a;
		if (w<=n)
			add(w,i);
	}
	printf("%d",f[n]);
}