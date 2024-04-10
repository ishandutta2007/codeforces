#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
#ifdef He_Ren
	freopen("in.txt","w",stdout);
#endif
	
	for(int i=0; i<=9; ++i)
		printf("\?\?%d>>%d\?\?\n",i,i);
	printf("\?\?>>\?\n");
	for(int i=0; i<9; ++i)
		printf("%d\?<>%d\n",i,i+1);
	printf("9\?>>\?0\n");
	printf("\?<>1\n");
	printf(">>\?\?\n");
	return 0;
}