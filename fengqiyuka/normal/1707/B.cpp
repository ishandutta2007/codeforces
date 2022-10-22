#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N];

bool cmp(int n1,int n2) {return (n1>n2);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		sort(a+1,a+n+1,cmp);
		
		int tot=n,Sum=0;
		while(tot&&a[tot]==0) Sum++,tot--;
		
		while(tot>=2){
			for(int i=1;i<tot;i++) a[i]=a[i]-a[i+1];
			tot--;
			if(Sum) tot++,Sum--;
			sort(a+1,a+tot+1,cmp);
			while(tot&&a[tot]==0) Sum++,tot--;
		}
		
		if(tot==0) printf("0\n");
		else printf("%d\n",a[1]);
	}
	
	return 0;
}