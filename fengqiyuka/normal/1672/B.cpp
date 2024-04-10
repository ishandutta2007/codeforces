#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
char s[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		if(s[len]=='A') printf("NO\n");
		else{
			int Sum=0;bool pd=true;
			for(int i=1;i<=len;i++){
				if(s[i]=='A') Sum++;
				if(s[i]=='B'){
					if(Sum==0){
						pd=false;
						break;
					}
					Sum--;
				}
			}
			if(!pd) printf("NO\n");
			else printf("YES\n");
		}
	}
	
	return 0;
}