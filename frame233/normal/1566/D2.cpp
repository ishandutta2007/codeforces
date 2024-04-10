#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=305*305;
int a[N],t[N],v[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n*m;++i)read(a[i]),t[i]=i;
	std::sort(t+1,t+n*m+1,[&](int x,int y){return a[x]==a[y]?x>y:a[x]<a[y];});
	int cur=0,p=0;
	for(int i=1;i<=n*m;++i){
		int j=i;while(j<n*m&&a[t[j+1]]==a[t[i]])++j;
		int len=j-i+1;
		if((cur+len-1)/m==cur/m)for(int k=i;k<=j;++k)v[++p]=t[k];
		else{
			int tmp=cur+len-1-(cur+len-1)/m*m+1;
			int need=m-cur%m;
			for(int k=j-need+1;k<=j;++k)v[++p]=t[k];
			for(int k=i+tmp;k<=j-need;++k)v[++p]=t[k];
			for(int k=i;k<i+tmp;++k)v[++p]=t[k];
		}
		i=j,cur+=len;
	}
	int ans=0;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)for(int k=j+1;k<=m;++k)ans+=v[(i-1)*m+j]<v[(i-1)*m+k];
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}