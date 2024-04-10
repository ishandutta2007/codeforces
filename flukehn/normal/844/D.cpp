#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
inline int _rand(){
	return (rand()<<15)^rand();
}
typedef pair<int,int> PII;
#define mp make_pair
inline PII query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int y;scanf("%d%d",&x,&y);
	return mp(x,y);
}
inline int print(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
const int inf=0x3f3f3f3f;
int now=-inf;
int main(){
	srand(unsigned((long long)new char));
	int n,St,opo,x,ff;
	scanf("%d%d%d",&n,&St,&opo);
	ff=St;
	rep(i,1,1000){
		x=_rand()%n+1;
		PII tmp;
		tmp=query(x);
		if(tmp.first==opo)print(tmp.first);
		if(tmp.first<opo&&tmp.first>now)St=tmp.second,now=tmp.first;
	}
	while(~St&&now<opo){
		PII tmp=query(St);
		if(tmp.first>=opo)print(tmp.first);
		else St=tmp.second;
	}
	print(-1);
}