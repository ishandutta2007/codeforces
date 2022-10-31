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
char in[210000];
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%s",in);
	int rem=0;
	int ren=0;
	for(int i=0;i<a;i++){
		if(in[i]=='0'){
			ren++;
		}else{
			rem+=ren/c;
			ren=0;
		}
	}
	rem+=ren/c;
	vector<int>ret;
	ren=0;
	for(int i=0;i<a;i++){
		if(rem<b)break;
		if(in[i]=='0'){
			ren++;
			if(ren%c==0){
				ret.push_back(i+1);
				rem--;
			}
		}else{
			ren=0;
		}
	}
	printf("%d\n",(int)(ret.size()));
	for(int i=0;i<ret.size();i++){
		if(i)printf(" ");
		printf("%d",ret[i]);
	}printf("\n");
}