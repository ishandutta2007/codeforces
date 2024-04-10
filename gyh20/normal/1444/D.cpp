#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[1002],b[1002],sx,sy;
bitset<1000002>F[1002];
inline void Get(int*A,int k,basic_string<int>&X,basic_string<int>&Y){
	F[0][0]=1;re int sum=0;X.clear(),Y.clear();
	for(re int i=1;i<=k;++i)F[i]=F[i-1]|(F[i-1]<<A[i]),sum+=A[i];
	if(sum&1||!F[k][sum>>1]){X.push_back(-1);return;}sum>>=1;
	for(re int i=n;i;--i)if(sum>=A[i]&&F[i-1][sum-A[i]])X.push_back(A[i]),sum-=A[i];else Y.push_back(-A[i]);
	sort(X.begin(),X.end()),sort(Y.begin(),Y.end());
}
basic_string<int>ans1x,ans1y,ans2x,ans2y;
int main(){
	t=read();
	while(t--){
		n=read(),sx=sy=0;
		for(re int i=1;i<=n;++i)a[i]=read(),sx+=a[i];
		m=read();
		for(re int i=1;i<=m;++i)b[i]=read(),sy+=b[i];
		if(n^m){
			puts("No");
			continue;
		}
		Get(a,n,ans1x,ans1y),Get(b,m,ans2x,ans2y);
		if(ans1x[0]==-1||ans2x[0]==-1){puts("No");continue;}
		else{
			puts("Yes");
			re int X=0,Y=0;
			if(ans1x.size()>ans2x.size()){
				reverse(ans2x.begin(),ans2x.end()),reverse(ans1y.begin(),ans1y.end()),ans1x+=ans1y,ans2x+=ans2y;
				for(re int i=0;i<ans1x.size();++i)printf("%d %d\n",X,Y+=ans2x[i]),printf("%d %d\n",X+=ans1x[i],Y);
			}
			else{
				reverse(ans2y.begin(),ans2y.end()),reverse(ans1x.begin(),ans1x.end()),ans1x+=ans1y,ans2x+=ans2y;
				for(re int i=0;i<ans1x.size();++i)printf("%d %d\n",X+=ans1x[i],Y),printf("%d %d\n",X,Y+=ans2x[i]);
			}
		}
	}
}