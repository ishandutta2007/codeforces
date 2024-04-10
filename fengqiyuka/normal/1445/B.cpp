#include<cstdio>
#include<cstring>
using namespace std;
int mymax(int x,int y) {return x>y?x:y;}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int A,B,C,D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		printf("%d\n",mymax(A+B,C+D));
	}
	return 0;
}