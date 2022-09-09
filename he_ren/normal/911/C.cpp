#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXK = 1500 + 5;

inline void YES(){ printf("YES"); exit(0);}
inline void NO(){ printf("NO"); exit(0);}

int a[3 + 5],t[MAXK];

int main(void)
{
	for(int i=1; i<=3; ++i)
		scanf("%d",&a[i]), ++t[a[i]];
	
	if(t[1]) YES();
	if(t[2]>=2) YES();
	if(t[3]==3) YES();
	if(t[4]==2 && t[2]) YES();
	NO();
	return 0;
}