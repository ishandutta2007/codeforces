#include<stdio.h>
#include<algorithm>
using namespace std;
int perm[8];
char str[8][9];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",str[i]);
	for(int i=0;i<b;i++)perm[i]=i;
	int ret=999999999;
	do{
		int l=999999999;
		int r=0;
		for(int i=0;i<a;i++){
			int c=0;
			for(int j=0;j<b;j++){
				c*=10;
				c+=str[i][perm[j]]-'0';
			}
			r=max(c,r);
			l=min(c,l);
		}
		ret=min(ret,r-l);
	}while(next_permutation(perm,perm+b));
	printf("%d\n",ret);
}