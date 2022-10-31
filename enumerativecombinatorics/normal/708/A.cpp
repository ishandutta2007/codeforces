#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
char in[110000];
int main(){
	scanf("%s",in);
	int n=strlen(in);
	bool ok=false;
	for(int i=0;i<n;i++){
		if(in[i]!='a'){
			ok=true;
			for(int j=i;j<n;j++){
				if(in[j]!='a')in[j]--;
				else break;
			}
			break;
		}
	}
	if(!ok){
		in[n-1]='z';
	}
	printf("%s\n",in);
}