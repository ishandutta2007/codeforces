#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int now=0,mini=1000,maxi=-1000;
	char d[500];
	int ans=0,g=0;
	scanf("%s",&d);
	for(int i=0;i<strlen(d);i++){
		if(d[i]=='+'){
			if(g>0){
				g--;
			}else{
			  ans++;
			}
		}else{
			g++;
		}
		ans=max(ans,g);
}
		printf("%d\n",ans);
	return 0;
}