#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#define pb push_back
#define ll long long
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n<0){
		n=-n;
		n=10*(n/100)+min(n%10,(n/10)%10);
		n=-n;
	}
	printf("%d",n);
	return 0;
}