#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int p[110];
char in[210];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	gets(in);
	for(int i=0;i<a;i++){
		gets(in);
		int cnt=0;
		for(int j=0;in[j];j++){
			if(in[j]=='a'||in[j]=='i'||in[j]=='u'||in[j]=='e'||in[j]=='o'||in[j]=='y'){
				cnt++;
			}
		}
		if(cnt!=p[i]){
			printf("NO\n");return 0;
		}
	}
	printf("YES\n");
}