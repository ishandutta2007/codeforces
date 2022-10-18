#include <bits/stdc++.h>


char s[1000];
int main(){
	int t;scanf("%d",&t);while(t--){
		int cnt=0;
		scanf("%s",s+1);
		for(int i=1;i<=12;++i){
			if (12%i)continue;
			int flag=0;
			for(int j=1;j<=12/i;++j){
				int flg=1;
				for(int k=j;k<=12;k+=12/i)if(s[k]=='O')flg=0;
			//	printf("%d %d\n",j,flg);
				flag|=flg;
			}
			if (flag)cnt++;
		}printf("%d ",cnt);
		for(int i=1;i<=12;++i){
			if (12%i)continue;
			int flag=0;
			for(int j=1;j<=12/i;++j){
				int flg=1;
				for(int k=j;k<=12;k+=12/i)if(s[k]=='O')flg=0;
			//	printf("%d %d\n",j,flg);
				flag|=flg;
			}
			if (flag)printf("%dx%d ",i,12/i);
		}printf("\n");
	}
}