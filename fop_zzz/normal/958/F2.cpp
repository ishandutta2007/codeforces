#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("F2.txt","r",stdin);
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
int a[200002];
int cnt[200002];
int main(){
	init();
	int n=readint(),m=readint();
	for(int i=1;i<=n;i++)	
		a[i]=readint();
	int qwq=0,sum=0;
	for(int i=1;i<=m;i++){
		cnt[i]=-readint();
		sum+=-cnt[i];
		if (cnt[i]<0)
			qwq++;
	}
	int r=1,ans=n+1;
	for(int i=1;i<=n;i++){
		while(r<=n && qwq){
			cnt[a[r]]++;
			if (cnt[a[r]]==0)
				qwq--;
			r++;
		}
		if (!qwq){
			// printf("%d\n",r);
			ans=min(ans,r-i);
		}
		if (cnt[a[i]]==0)
			qwq++;
		cnt[a[i]]--;
	}
	printf("%d",ans==n+1?-1:ans-sum);
}