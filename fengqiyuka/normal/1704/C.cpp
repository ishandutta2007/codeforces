#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N],b[N];

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		sort(a+1,a+m+1,cmp);
		
		a[0]=a[m]-n;
		for(int i=1;i<=m;i++){
			b[i]=a[i]-a[i-1]-1;
		}
		
		sort(b+1,b+m+1,cmp);
		
		int st=0,Ans=0;
		for(int i=m;i>=1;i--){
			if(b[i]-st==1){
				Ans++;st+=2;
			}
			else if(b[i]-st>1){
				Ans+=(b[i]-st-1);
				st+=4;
			}
		}
		
		printf("%d\n",n-Ans);
	}
	
	return 0;
}