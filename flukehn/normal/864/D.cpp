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
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=200011;
int n,A[N];
int num[N];
bool mark[N];
int sta[N],sop;
int main(){
	n=rd();
	rep(i,1,n){
		A[i]=rd();
		num[A[i]]++;
	}
	int cnt=0;
	int now=1;
	rep(i,1,n){
		if(mark[A[i]]){
			while(now<=n&&num[now]){
				now++;
			}
			cnt++;
			mark[now]=num[now]=1;
			sta[++sop]=now;
		}
		else if(num[A[i]]==1){
			//debug(now);
			sta[++sop]=A[i];
			num[A[i]]=mark[A[i]]=1;
		}
		else if(num[A[i]]>1){
			while(now<=n&&num[now]) {
				now++;
			}
			//if(now==1)cout<<" f "<<num[now]<<endl;
			//cout << A[i] << " " << now << endl;
			if(A[i] < now) {
				sta[++sop]=A[i];
				mark[A[i]]=1;
			}else {
				num[A[i]]--;
				sta[++sop]=now;
				mark[now]=num[now]=1;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	rep(i,1,n)printf("%d%c",sta[i]," \n"[i==n]);
}