#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N],f[N];
map<int,int> B;

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		B[0]=-1;
		int Sum=0;
		for(int i=1;i<=n;i++){
			Sum=(Sum^a[i]);
			f[i]=std::min(B[Sum]+i,f[i-1]+1);
			B[Sum]=std::min(B[Sum],f[i]-i-1);
		}
		
		printf("%d\n",f[n]);
		
		B.clear();
	}
	
	return 0;
 }