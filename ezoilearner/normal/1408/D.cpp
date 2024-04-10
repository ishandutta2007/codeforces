#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n,m;
#define Maxn 2005
struct Data{
	int a,b;
	Data(){a=b=0;}
}A[Maxn],B[Maxn];
int mx[N+10];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>A[i].a>>A[i].b;
	for(int i=1;i<=m;++i)cin>>B[i].a>>B[i].b;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(B[i].a>=A[j].a)mx[B[i].a-A[j].a+1]=max(mx[B[i].a-A[j].a+1],B[i].b-A[j].b+1);
	int ans=N,tmp=0;
	for(int i=N;i>=0;--i){
		ans=min(ans,i+tmp);
		tmp=max(tmp,mx[i]);
	}
	printf("%d\n",ans);
	return 0;
}