#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int a[36][36],n,m,c[36],ans;
inline void work(){
	for(re int i=m+1;i<=n;++i)c[i]=c[i-m]^c[m];
	re int sum=0;
	for(re int i=1;i<=n;++i)if(c[i])sum-=a[m][i];else sum+=a[m][i];
	for(re int i=1;i<m;++i){
		re int t0=0,t1=0;
		for(re int j=1;j<m;++j){
			re int s0=0,s1=0,s=0;
			s+=a[i][j];
			if(c[j])s-=a[i+m][j];else s+=a[i+m][j];
			s0=s1=s;
			s0+=a[i][j+m],s1-=a[i][j+m];
			if(c[j]^c[m])s0-=a[i+m][j+m],s1+=a[i+m][j+m];
			else s0+=a[i+m][j+m],s1-=a[i+m][j+m];
			if(s0<0)s0=-s0;if(s1<0)s1=-s1;
			t0+=s0,t1+=s1;
		}
		t0+=a[i][m],t1-=a[i][m];
		if(c[m])t0-=a[i+m][m],t1+=a[i+m][m];
		else t0+=a[i+m][m],t1-=a[i+m][m];
		if(t0>t1)sum+=t0;
		else sum+=t1;
	}
	if(sum>ans)ans=sum;
}
inline void dfs(re int x){
	if(x==m+1)return work();
	c[x]=0,dfs(x+1);
	c[x]=1,dfs(x+1);
}
int main(){
	n=read(),m=n+1>>1,ans=-114514;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			a[i][j]=read();
	dfs(1),printf("%d",ans);
}