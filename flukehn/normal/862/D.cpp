#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1500;
int n;
char s[N];
void print(){
	putchar('?'),putchar(' ');
	puts(s+1);
	fflush(stdout);
}
int main(){
	n=rd();
	rep(i,1,n)s[i]='0';
	print();
	int x=rd(),y,a,b;
	s[n]='1';
	print(),y=rd();
	if(y>x){
		a=n;
		int l=1,r=n-1;
		while(l<r){
			int mid=l+r>>1;
			rep(i,l,mid)s[i]='1';
			print();
			rep(i,l,mid)s[i]='0';
			int ge=rd();
			if(ge==y+(mid-l+1))l=mid+1;
			else r=mid;
		}
		b=l;
	}else{
		b=n;
		int l=1,r=n-1;
		rep(i,1,n)s[i]='1';
		print(),y=rd();
		while(l<r){
			int mid=l+r>>1;
			rep(i,l,mid)s[i]='0';
			print();
			rep(i,l,mid)s[i]='1';
			int ge=rd();
			if(ge==y+(mid-l+1))l=mid+1;
			else r=mid;
		}
		a=l;
	}
	printf("! %d %d\n",a,b);
	fflush(stdout);
}