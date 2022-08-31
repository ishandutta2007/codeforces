#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[100002],cnt;
map<int,int>v;
char s[100002];
long long ans,sum;
int main(){
	t=read();
	while(t--){
		n=read();
		scanf("%s",s+1);
		ans=0,sum=0;v.clear();v[0]=1;
		for(re int i=1;i<=n;++i)a[i]=s[i]-'0'-1,sum+=a[i],ans+=v[sum],++v[sum];;
		printf("%lld\n",ans);
	}
}