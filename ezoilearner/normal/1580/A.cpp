#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int T,n,m;
#define Maxn 405
int sum[Maxn][Maxn];
char s[Maxn];
char ch[Maxn][Maxn];

int calc(int p1,int p2){
	int cur=0;
	rep(i,2,4)cur+=sum[i][p2-1]-sum[i][p1]+('1'-ch[i][p1])+('1'-ch[i][p2]);
	int res=100,tmp=100;
	rep(i,5,n){
		tmp=min(tmp,cur+p2-p1-1-(sum[i-4][p2-1]-sum[i-4][p1]));
		res=min(res,tmp+p2-p1-1-(sum[i][p2-1]-sum[i][p1]));
		cur-=(sum[i-3][p2-1]-sum[i-3][p1]+('1'-ch[i-3][p1])+('1'-ch[i-3][p2]));
		int zz=sum[i][p2-1]-sum[i][p1]+('1'-ch[i][p1])+('1'-ch[i][p2]);
		cur+=zz;tmp+=zz;
	}
	return res;
}

int main(){
	rd(T);//a>=5,b>=4
	while(T--){
		rd(n);rd(m);int Ans=100;
		rep(i,1,n){
			scanf("%s",s+1);
			rep(j,1,m)sum[i][j]=sum[i][j-1]+s[j]-'0',ch[i][j]=s[j];
		}
		rep(p1,1,m-3)
			rep(p2,p1+3,m)Ans=min(Ans,calc(p1,p2));
		printf("%d\n",Ans);
	}
	return 0;
}