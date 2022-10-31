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
int UF[210000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
vector<int>A;
vector<int>B;
int v[210000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a*2;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		UNION(p,q+a);
		UNION(q,p+a);
	}
	for(int i=0;i<a;i++){
		if(FIND(i)==FIND(i+a)){
			printf("-1\n");return 0;
		}
	}
	for(int i=0;i<a;i++){
		if(v[FIND(i)]==0&&v[FIND(i+a)]==0){
			v[FIND(i)]=1;
			v[FIND(i+a)]=-1;
			A.push_back(i);
		}else{
			if(v[FIND(i)]==1||v[FIND(i+a)]==-1){
				v[FIND(i)]=1;
				v[FIND(i+a)]=-1;
				A.push_back(i);
			}else{
				v[FIND(i)]=-1;
				v[FIND(i+a)]=1;
				B.push_back(i);
			}
		}
	}
	printf("%d\n",(int)A.size());
	for(int i=0;i<A.size();i++){
		if(i)printf(" ");printf("%d",A[i]+1);
	}
	printf("\n");
	printf("%d\n",(int)B.size());
	for(int i=0;i<B.size();i++){
		if(i)printf(" ");printf("%d",B[i]+1);
	}
	printf("\n");
}