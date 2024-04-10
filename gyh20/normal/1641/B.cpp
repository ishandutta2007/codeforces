#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,A,B,a[1000002],b[1000002],t,ans,sum;
char s[1000002];
vector<int>T,O,C;
inline void Do(re int x,re int y){
	O.push_back(x+sum),C.push_back(y);
}
inline void Flip(re int x){
	re int pos=x;
	for(re int i=1;i<=x;++i)Do(pos,a[i]),++pos;
	T.push_back(x<<1),sum+=x<<1;
}
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0;T.clear(),O.clear(),C.clear(),sum=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		re bool ia=1;
		while(n){
			re int pos=0;
			for(re int i=2;i<=n;++i)if(a[i]==a[1]){pos=i;break;}
			if(!pos){
				ia=0;
				break;
			}
			Flip(pos-1),reverse(a+1,a+pos),Flip(pos);
			reverse(a+1,a+pos+1);
			T.push_back(2),sum+=2;
			for(re int i=1;i<=n-2;++i)a[i]=a[i+2];n-=2;
		}
		if(!ia){
			puts("-1");
			continue;
		}
		printf("%d\n",C.size());
		for(re int i=0;i<C.size();++i)printf("%d %d\n",O[i],C[i]);
		printf("%d\n",T.size());
		for(re int i=0;i<T.size();++i)printf("%d ",T[i]);
		puts("");
	}
}