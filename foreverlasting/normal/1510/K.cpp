#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e3+10;
#define res register int
#define gc getchar
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
inline void swap(res &x,res &y){
	x^=y^=x^=y;
}
int a[N],b[N];
int main(){
	n=read();
	for(res i=1;i<=2*n;i++)a[i]=b[i]=read();
	res FL=0;
	for(res i=1;i<=2*n;i++)if(a[i]!=i){FL=1;break;}
	if(!FL){puts("0");return 0;}
	res ret=0;
	while(233){
		if(ret>=30000){ret=-1;break;}
		if(ret&1){
			for(res i=1;i<=n;i++)swap(a[i<<1],a[(i<<1)-1]);
		}
		else for(res i=1;i<=n;i++)swap(a[i],a[i+n]);
		ret++;
		res fl=0;
		for(res i=1;i<=2*n;i++)if(a[i]!=i){fl=1;break;}
		if(!fl)break;
	}
	res ans=ret;
	ret=0;
	for(res i=1;i<=2*n;i++)a[i]=b[i];
	while(233){
		if(ret>=30000){ret=-1;break;}
		if(ret&1){
			for(res i=1;i<=n;i++)swap(a[i],a[i+n]);
		}
		else for(res i=1;i<=n;i++)swap(a[i<<1],a[(i<<1)-1]);
		ret++;
		res fl=0;
		for(res i=1;i<=2*n;i++)if(a[i]!=i){fl=1;break;}
		if(!fl)break;
	}
	if(ans==-1)ans=ret;
	else if(ret!=-1)ans=min(ans,ret);
	printf("%d\n",ans);
	return 0;
}