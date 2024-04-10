#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N];

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		
		int n,X;
		scanf("%d%d",&n,&X);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
		int Min=1e9,Max=-1e9,Ans=0;
		for(int i=1;i<=n;i++){
			Min=std::min(Min,a[i]);
			Max=std::max(Max,a[i]);
			if(Max-Min>2*X){
				Ans++;
				Min=Max=a[i];
			}
		}
		
		printf("%d\n",Ans);
	}
	
	return 0;
}