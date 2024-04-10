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
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1;
int n;
char ch[N];
V input(){
	scanf("%d",&n);
}
V init(){
	
}
V work(){
	while(n--){
		rnt sum=0,zero=0,two=0,len;
		scanf("%s",ch+1),len=strlen(ch+1);
		if(len==1){
			if(ch[1]=='0')
				cout<<"red\n";
			else cout<<"cyan\n";
			continue;
		}
		FOR(i,1,len){
			sum+=ch[i]-48;
			zero+=ch[i]=='0';
			two+=ch[i]%2==0;
		}
		if(sum%3==0&&zero&&two>=2)
			cout<<"red\n";
		else cout<<"cyan\n";
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}