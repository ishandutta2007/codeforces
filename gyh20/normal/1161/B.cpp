#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
using namespace std;
vector<int>v[201010];
int a[200002],b[200002],x,y,n,m;
inline int dis(int x,int y){
	if(x>y)return min(x-y,y-x+n);
	else return min(y-x,x-y+n);
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i)x=read(),y=read(),v[x].push_back(y),v[y].push_back(x);
	for(int i=1,tmp=1;i<n;++i){
		if(n%i==0){
			int ia=1;
			for(int j=1;j<=n;++j){
				if(v[j].size()^v[(j+i-1)%n+1].size()){ia=0;break;}
				for(re int k=0;k<v[j].size();++k)a[k]=dis(v[j][k],j),b[k]=dis(v[(j+i-1)%n+1][k],(j+i-1)%n+1);
				sort(a,a+v[j].size()),sort(b,b+v[j].size());
				for(re int k=0;k<v[j].size();++k)if(a[k]^b[k]){ia=0;break;}
			 }
			 if(ia)return puts("Yes"),0;
		 }
	 }
	puts("No");
}