#include<bits/stdc++.h>
using namespace std;

const int N=55;
char s1[N],s2[N];

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		
		int Sum1=0,Sum2=0;
		for(int i=1;i<=n-m+1;i++){
			if(s1[i]=='0') Sum1++;
			if(s1[i]=='1') Sum2++;
		}
		
		if((s2[1]=='0'&&Sum1)||(s2[1]=='1'&&Sum2)){
			bool pd=true;
			
			for(int i=2;i<=m;i++){
				if(s1[n-m+i]!=s2[i])
					{pd=false;break;}
			}
			
			if(pd) printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
		
	}
	
	return 0;
}