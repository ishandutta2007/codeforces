#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

const int st=10000005;
int n,da,db,t[105],gowno;
char a[st],b[st];

int main()
{
	scanf("%d%d",&n,&gowno);
	scanf("%s",a);
	scanf("%s",b);

	da=strlen(a);
	db=strlen(b);

	for(int i=0;i<db;++i){
		int k=i;
		for(int j=0;j<da;++j)
			if(a[j]==b[k%db])k++;
		t[i]=k;
	}
	int RES=0,pom=0;
	while(n--){
		pom=t[pom];
		RES+=pom/db;
		pom%=db;
	}
	printf("%d",RES/gowno);
	return 0;
}