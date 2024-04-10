#include<bits/stdc++.h>
using namespace std;
main(){
	char s[200005];
	scanf("%s",s);
	int ok=0;
	for(int i=0;s[i]!=0;i++){
		if(s[i]!='a')
		printf("%c",s[i]-1),ok=1;
		else if(ok){
			for(;s[i]!=0;i++)
			printf("%c",s[i]);
			break;
		}
		else{
			if(s[i+1]==0)
			printf("z");
			else
			printf("a");
		}
	}
	
}