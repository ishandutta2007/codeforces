#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int read() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
int main()
{
	double h=read(),m=read(),s=read();
	double s1=read()*30,s2=read()*30;
	double tt1=6*s;
	double tt2=6*m+s/10.0;
	if(h==12) h=0;
	double ch=h*30+m/2.0+s/120.0;
	if((((tt1>=s1&&tt1<=s2)||(tt2>=s1&&tt2<=s2)||(ch>=s1&&ch<=s2))&&s1<=s2)||(s1>s2&&(((tt1>=s1&&tt1<=360)||(tt1>=0&&tt1<=s2))||((tt2>=s1&&tt2<=360)||(tt2>=0&&tt2<=s2))||((ch>=s1&&ch<=360)||(ch>=0&&ch<=s2))))){
		swap(s1,s2);
		if((((tt1>=s1&&tt1<=s2)||(tt2>=s1&&tt2<=s2)||(ch>=s1&&ch<=s2))&&s1<=s2)||(s1>s2&&(((tt1>=s1&&tt1<=360)||(tt1>=0&&tt1<=s2))||((tt2>=s1&&tt2<=360)||(tt2>=0&&tt2<=s2))||((ch>=s1&&ch<=360)||(ch>=0&&ch<=s2)))))
		{
			printf("NO");
		}
		else printf("YES");
	}
	else printf("YES");
}