#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
long long n,m,l[100002],a[100002],v[100002],num[1000002],mn[100002],mx[100002],pp;
long long ans;
int main(){
n=pp=read();
memset(mn,127,sizeof(mn));
for(re int i=1;i<=n;++i){
	l[i]=read();
	for(re int j=1;j<=l[i];++j){
		a[j]=read();
		if(a[j]>mx[i])mx[i]=a[j];
		if(a[j]<mn[i])mn[i]=a[j];
		if(j!=1&&a[j]>a[j-1]){
			v[i]=1;
		}
	}
	if(v[i])ans+=pp+pp-1,--pp;
	else ++num[mn[i]];
}
for(re int i=1;i<=1000000;++i)num[i]+=num[i-1];
for(re int i=1;i<=n;++i){
	if(!v[i]){
//		cout<<i<<" "<<num[mx[i]-1]<<endl;
		ans+=num[mx[i]-1];
	}
}
printf("%lld",ans);
}