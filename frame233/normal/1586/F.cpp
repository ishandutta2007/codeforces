#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;
int a[N][11];
int main(){
	int n,k;read(n,k);
	int l=0,v=1;while(v<n)v*=k,++l;
	for(int i=0;i<n;++i)for(int j=0,x=i;j<l;++j)a[i][j]=x%k,x/=k;
	printf("%d\n",l);
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			for(int k=l-1;k>=0;--k)if(a[i][k]!=a[j][k]){printf("%d ",k+1);break;}
		}
	}
	printf("\n");
	return 0;
}