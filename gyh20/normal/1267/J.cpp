#include<cstdio>
#include<iostream>
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
int t,n,a[2000002],mn,p[2000002],cnt;
int main(){
	t=read();
	while(t--){
		n=read();
		mn=0x7fffffff;
		cnt=0;
		bool ia=0;
		for(re int i=1;i<=n;++i)++a[read()];
		for(re int i=1;i<=n;++i)if(a[i])mn=min(mn,a[i]),p[++cnt]=a[i],a[i]=0;int ans=0;
		++mn;
		while(1){
			ans=0;
			ia=0;
			for(re int i=1;i<=cnt;++i){
				int tmp=(p[i]-1)/mn+1;
				ans+=tmp;
				if((mn-1)*tmp>p[i]){ia=1;break;
				}
			}
			if(!ia)break;
			--mn;
		}
		printf("%d\n",ans);
	}
}