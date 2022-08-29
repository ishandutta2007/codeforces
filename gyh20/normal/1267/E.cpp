#include<cstdio>
#include<algorithm>
#define in inline
#define re register
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
int n,m,ans[102],v[102][102],mn,sum[102];
struct piao{
	int pos,vot;
}q[102];
inline bool cmp(re piao x,re piao y){
	return x.vot>y.vot;
}
int main(){
	n=read();
	m=read();
	mn=0x7fffffff;
	for(re int i=1;i<=m;++i)
		for(re int j=1;j<=n;++j)
			v[i][j]=read(),sum[j]+=v[i][j];
	for(re int i=1;i<n;++i){
		for(re int j=1;j<=m;++j){
		q[j].pos=j;
		q[j].vot=v[j][n]-v[j][i];
		}
		sort(q+1,q+m+1,cmp);
		int tmp=sum[i]-sum[n],tmp1=0;
		while(tmp<0){
			tmp+=q[++tmp1].vot;
		}
		if(tmp1<mn){
			mn=tmp1;
			for(re int j=1;j<=tmp1;++j){
				ans[j]=q[j].pos;
			}
		}
	}
	printf("%d\n",mn);
	for(re int i=1;i<=mn;++i)printf("%d ",ans[i]);
}