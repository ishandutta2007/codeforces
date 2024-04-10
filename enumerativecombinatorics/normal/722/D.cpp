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
int b[60000];
int ans[60000];
int n;
bool chk(int a){
	set<int>S;
	for(int i=0;i<n;i++){
		int c=b[i];
		bool ok=false;
		while(c){
			if(c<=a&&!S.count(c)){
				ok=true;break;
			}
			c/=2;
		}
		if(!ok)return false;
		S.insert(c);
		ans[i]=c;
	}
	return true;
}
int main(){
	int a;scanf("%d",&a);
	n=a;
	for(int i=0;i<a;i++)scanf("%d",b+i);
	int left=0;
	int right=mod;
	while(left+1<right){
		int M=(left+right)/2;
		if(chk(M)){
			right=M;
		}else left=M;
	}
	chk(right);
	for(int i=0;i<a;i++){
		if(i)printf(" ");printf("%d",ans[i]);
	}
	printf("\n");
}