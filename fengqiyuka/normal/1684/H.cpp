#include<bits/stdc++.h>
using namespace std;

const int N=1e6+100;
char s[N];int Ans[N][2];

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		
		int len=strlen(s+1),Sum=0;
		for(int i=1;i<=len;i++){
			if(s[i]=='1') Sum++;
		}
		
		if(Sum==0){
			printf("-1\n");
			continue;
		}
		
		int d=1;
		while(d<Sum) d=d*2;
		
		int now=0,tot=0,L=1,tmp=Sum;
		for(int i=1;i<=len;i++){
			int t=now;
			if(Sum+t<=d) Sum=Sum+t;
			else{
				Ans[++tot][0]=L;Ans[tot][1]=i-1;
				L=i;now=0;
			}
			
			now=now*2+s[i]-'0';
		}
		Ans[++tot][0]=L;Ans[tot][1]=len;
		
		if(Sum<d){
			Sum=tmp;now=0,tot=0,L=1;d*=2;
			for(int i=1;i<=len;i++){
				int t=now;
				if(Sum+t<=d) Sum+=t;
				else{
					Ans[++tot][0]=L;Ans[tot][1]=i-1;
					L=i;now=0;
				}
				
				now=now*2+s[i]-'0';
			}
			Ans[++tot][0]=L;Ans[tot][1]=len;
		}
		
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++) printf("%d %d\n",Ans[i][0],Ans[i][1]);
	}
	
	return 0;
}