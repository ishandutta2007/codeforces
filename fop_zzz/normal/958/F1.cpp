#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	#ifdef LOCAL
		freopen("F1.txt","r",stdin);
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
int cnt[233],now[233];
int a[233];
int main(){
	init();
	int n=readint(),m=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	for(int i=1;i<=m;i++)
		cnt[i]=readint();
	for(int i=1;i<=n;i++){
		memset(now,0,sizeof(now));
		for(int j=i;j<=n;j++){
			now[a[j]]++;
			bool flag=true;
			for(int k=1;k<=m;k++)
				if (now[k]!=cnt[k])
					flag=false;
			if (flag)
				return puts("YES");
		}
	}
	puts("NO");
}