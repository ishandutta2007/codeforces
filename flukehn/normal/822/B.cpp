#include<bits/stdc++.h>
using namespace std;
const int N=2100;
char a[N],b[N];
int m,n;
int cal(int x){
	int re=0,i,j;
	for(i=1,j=x;i<=n&&j<=m;i++,j++)
		re+=(a[i]!=b[j]);
	re+=n-i+1;
	return re;
}
int x,ans=~0u>>2;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=m-n+1;i++){
		int t=cal(i);
		if(t<ans)ans=t,x=i;
	}
	cout<<ans<<endl;
	for(int i=1,j=x;i<=n;i++,j++)
		if(a[i]!=b[j])cout<<i<<" ";
}