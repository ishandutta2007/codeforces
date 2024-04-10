#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
#define Maxn 105
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];
int A[Maxn][Maxn];
bool b[2][2];
pii ans[30010];int cnt;
 
void output(int t1,int t2,int t3,int t4,int t5,int t6){
	A[t1][t2]^=1;A[t3][t4]^=1;A[t5][t6]^=1;
	ans[++cnt]=pii(t1,t2);ans[++cnt]=pii(t3,t4);ans[++cnt]=pii(t5,t6);
}
 
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
 
int main(){
	int T;rd(T);
	while(T--){
		cnt=0;
		rd(n);rd(m);
		for(int i=1;i<=n;++i){
			scanf("%s",ch+1);
			for(int j=1;j<=m;++j)A[i][j]=ch[j]-'0';
		}
		for(int i=1;i<=n-2;++i)
			for(int j=1;j<=m;++j)
				if(A[i][j]){
					if(j<m)output(i,j,i+1,j,i+1,j+1);
					else output(i,j,i+1,j-1,i+1,j);
				}
		for(int j=1;j<=m-2;++j)
		if(A[n-1][j]||A[n][j]){
			if(A[n-1][j]&&A[n][j])output(n-1,j,n,j,n,j+1);
			else{
				if(A[n-1][j])output(n-1,j,n-1,j+1,n,j+1);
				else output(n,j,n,j+1,n-1,j+1);
			}
		}
		b[0][0]=b[0][1]=b[1][0]=b[1][1]=0;
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)
			if(A[n-1+i][m-1+j]){
				for(int t1=0;t1<2;++t1)for(int t2=0;t2<2;++t2)b[t1][t2]^=1;
				b[i^1][j^1]^=1;
			}
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)
			if(b[i][j]){
				for(int t1=0;t1<2;++t1)for(int t2=0;t2<2;++t2)
					if(t1==i||t2==j)ans[++cnt]=pii(n-1+t1,m-1+t2);
			}
		printf("%d\n",cnt/3);
		for(int i=1;i<=cnt;i+=3){
			printf("%d %d %d %d %d %d\n",ans[i].FR,ans[i].SE,ans[i+1].FR,ans[i+1].SE,ans[i+2].FR,ans[i+2].SE);
		}
	}
	return 0;
}