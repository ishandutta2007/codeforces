#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define st first
#define nd second
const int nax=1000123;

int n,m;
map<int,int> tak;

int main()
{
	scanf("%d%d",&n,&m);
	while(m--){
		int a;
		scanf("%d",&a);
		tak[a]=1;
		if((tak[a+1]&&tak[a+2])||(tak[a-1]&&tak[a+1])||(tak[a-2]&&tak[a-1])||a==1||a==n){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}