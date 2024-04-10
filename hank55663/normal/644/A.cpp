#include<bits/stdc++.h>
main(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if(a*b<n)
	printf("-1\n");
	else if(b%2==1)
	{
		for(int i=0;i<a;i++)
		for(int j=0;j<b;j++){
			printf("%d%c",n?n--:0,j==b-1?'\n':' ');
		}
	}
	else{
		for(int i=0;i<a;i++){
			if(i%2==0)
			for(int j=0;j<b;j++){
				printf("%d%c",n?n--:0,j==b-1?'\n':' ');
			}
			if(i%2==1)
			{
				printf("%d ",n-b+1>0?n-b+1:0);
				for(int j=1;j<b;j++)
				{
					printf("%d%c",n?n--:0,j==b-1?'\n':' ');
				}
				n?n--:0;
			}
		}
	}
}