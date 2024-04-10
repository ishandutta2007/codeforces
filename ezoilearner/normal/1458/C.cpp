#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int C[1005][1005],D[1005][1005];
char ch[Maxn];

struct Matrix{
	int num[5][5],len1,len2;
	Matrix(){
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)num[i][j]=0;
	}
	void init(){
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)num[i][j]=0;
	}
	friend Matrix operator *(Matrix t1,Matrix t2){
		Matrix res;res.len1=t1.len1;res.len2=t2.len2;
			for(int j=1;j<=t1.len2;++j)
					for(int k=1;k<=t2.len2;++k)
						if(t2.num[j][k])
						for(int i=1;i<=t1.len1;++i)
						res.num[i][k]=(res.num[i][k]+1ll*t1.num[i][j]*t2.num[j][k])%n;
		return res;
	}
}B,A,F;

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
	int t;rd(t);
	while(t--){
		rd(n);rd(m);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)rd(C[i][j]);
		scanf("%s",ch+1);
	B.len1=B.len2=4;B.init();
	for(int i=1;i<=4;++i)B.num[i][i]=1;
	A.len1=A.len2=4;
		for(int i=1;i<=m;++i){
			for(int j=1;j<=4;++j)for(int k=1;k<=4;++k)
				if(j!=k)A.num[j][k]=0;
				else A.num[j][k]=1;
			if(ch[i]=='L'){
				A.num[4][2]=n-1;
			}
			if(ch[i]=='R'){
				A.num[4][2]=1;
			}
			if(ch[i]=='U'){
				A.num[4][1]=n-1;
			}
			if(ch[i]=='D'){
				A.num[4][1]=1;
			}
			if(ch[i]=='I'){
				A.num[2][2]=A.num[3][3]=0;
				A.num[3][2]=1;A.num[2][3]=1;
			}
			if(ch[i]=='C'){
				A.num[1][1]=A.num[3][3]=0;
				A.num[3][1]=1;A.num[1][3]=1;
			}
			B=B*A;
		}
		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				int k=C[i][j]-1;
				F.len1=1;F.len2=4;
				F.num[1][1]=i;F.num[1][2]=j;F.num[1][3]=k;F.num[1][4]=1;
				F=F*B;
				D[F.num[1][1]][F.num[1][2]]=F.num[1][3];	
			}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)printf("%d ",D[i][j]+1);
			puts("");
		}
		puts("");
	}
	return 0;
}