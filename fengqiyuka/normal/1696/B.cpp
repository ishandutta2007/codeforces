#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N];

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		a[0]=0;
		
		int Sum=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]==0&&a[i]>0) Sum++;
		}
		printf("%d\n",std::min(Sum,2));
	}
	
	return 0;
}