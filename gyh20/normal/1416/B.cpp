#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[300002],mn,ans[300002],m,lst[300002],num[300002],ave,ans1[900002],ans2[900002],ans3[900002],cnt,p[300002];
inline bool cmp(re int x,re int y){
	return x-a[x]<y-a[y];
}
signed main(){
	int t=read();
	while(t--){
		n=read();
		re int sum=0;cnt=0;
		for(re int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
		if(sum%n){
			puts("-1");
			continue;
		}ave=sum/n;
		for(re int i=2;i<=n;++i){
			re int j=(a[i]-1)/i+1,jj=(i-a[i]%i)%i;
			ans1[++cnt]=1,ans2[cnt]=i,ans3[cnt]=jj;
			ans1[++cnt]=i,ans2[cnt]=1,ans3[cnt]=j;
		}
		for(re int i=2;i<=n;++i)ans1[++cnt]=1,ans2[cnt]=i,ans3[cnt]=ave;if(cnt>3*n)while(1);
		printf("%lld\n",cnt);
		for(re int i=1;i<=cnt;++i)printf("%lld %lld %lld\n",ans1[i],ans2[i],ans3[i]);
	}
}