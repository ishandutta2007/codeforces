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

int t[4][4];
char slowo[50];

int main()
{
	int z;
	scanf("%d",&z);
	while(z--){
		for(int i=0;i<8;++i){
			scanf("%s",slowo);
			for(int j=0;j<8;++j)
				if(slowo[j]=='K')t[i%4][j%4]++;
		}
		int ma=0;
		for(int i=0;i<4;++i)for(int j=0;j<4;++j)ma=max(ma,t[i][j]);
		if(ma==2)printf("YES\n");
		else printf("NO\n");
		for(int i=0;i<4;++i)for(int j=0;j<4;++j)t[i][j]=0;
	}
	return 0;
}