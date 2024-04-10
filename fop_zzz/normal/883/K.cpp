#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
#define maxnEG 0
void init(){
	#ifdef LOCAL
		freopen("K.txt","r",stdin);
	#endif
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if maxnEG
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
const int maxn=200002;
ll s[maxn],g[maxn],answ[maxn],mmin[maxn],mmax[maxn];
int main(){
	init();
	int n=readint();
	ll sum=0;
	for(int i=1;i<=n;i++)
		s[i]=readint(),g[i]=readint();
	mmin[0]=-1;
	mmax[0]=2000010;
	for(int i=1;i<=n;i++){
		mmin[i]=max(mmin[i-1]-1,s[i]);
		mmax[i]=min(mmax[i-1]+1,s[i]+g[i]);
		sum-=s[i];
		if (mmin[i]>mmax[i])
			return puts("-1"),0;
	}
	answ[n]=mmax[n];
	sum+=mmax[n];
	for(int i=n-1;i;i--){
		answ[i]=min(answ[i+1]+1,mmax[i]);
		sum+=answ[i];
	}
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)
		printf("%lld ",answ[i]);
}