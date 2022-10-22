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

int n,m;
#define Maxn 1505
int type[Maxn][Maxn];
int seq[Maxn],cnt=0;
int ton[Maxn];
int y[Maxn];

void sort(int A[][Maxn],int *sa){
	rep(i,1,n)sa[i]=i;
	per(j,m,1){
		rep(i,0,n)ton[i]=0,y[i]=sa[i];
		rep(i,1,n)ton[A[sa[i]][j]]++;
		rep(i,1,n)ton[i]+=ton[i-1];
		rep(i,1,n)sa[ton[A[y[i]][j]]--]=y[i];
	}
}
int sa1[Maxn],sa2[Maxn];

int A[Maxn][Maxn],B[Maxn][Maxn];
vector<int> v[Maxn];
int val[Maxn];bool vis[Maxn];

int Q[Maxn],hd,tl;
bool flag[Maxn];

int main(){
	rd(n);rd(m);
	rep(i,1,n)rep(j,1,m)rd(A[i][j]);
	rep(i,1,n)rep(j,1,m)rd(B[i][j]);
	sort(A,sa1);sort(B,sa2); 
	rep(i,1,n){
		int t1=sa1[i],t2=sa2[i];
		rep(j,1,m)
			if(A[t1][j]!=B[t2][j]){
				puts("-1");
				return 0;
			}
	}
	rep(i,2,n){
		flag[i]=true;
		rep(j,1,m)
			if(B[i-1][j]<B[i][j])type[i][j]=1,v[j].push_back(i),flag[i]=false;
			else if(B[i-1][j]>B[i][j])type[i][j]=-1,val[j]++,flag[i]=false;
			else type[i][j]=0;
	}
	rep(i,1,m)
		if(!val[i])Q[tl++]=i;
	while(hd<tl){
		int u=Q[hd];hd++;
		for(int i=0;i<v[u].size();++i){
			int to=v[u][i];
			if(!vis[to]){
				vis[to]=true;
				rep(j,1,m)
					if(type[to][j]==-1){
						val[j]--;
						if(!val[j])Q[tl++]=j;
					}
			}
		}
	}
	rep(i,2,n)
		if(!flag[i]&&!vis[i]){
			puts("-1");
			return 0;
		}
	printf("%d\n",tl);
	reverse(Q,Q+tl);
	rep(i,0,tl-1)printf("%d ",Q[i]);
	return 0;
}