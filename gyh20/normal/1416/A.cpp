#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[300002],mn,ans[300002],m,lst[300002],num[300002];
int main(){
	int t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),ans[i]=1e9,lst[i]=0,num[i]=0;
		for(re int i=1;i<=n;++i){
			num[a[i]]=max(num[a[i]],i-lst[a[i]]);
			lst[a[i]]=i;
		}
		for(re int i=1;i<=n;++i)num[i]=max(num[i],n+1-lst[i]);
		for(re int i=1;i<=n;++i)ans[num[i]]=min(ans[num[i]],i);
		for(re int i=2;i<=n;++i)ans[i]=min(ans[i],ans[i-1]);
		for(re int i=1;i<=n;++i)printf("%d ",ans[i]==1e9?-1:ans[i]);
		puts("");
	}
}