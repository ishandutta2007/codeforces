#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> P;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define p push
int num[3]={};
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int g;
		scanf("%d",&g);
		num[i%3]+=g;
	}
	if(num[0]>num[1] && num[0]>num[2]){
		puts("back");
	}else if(num[1]>num[0] && num[1]>num[2]){
		puts("chest");
	}else{
		puts("biceps");
	}
	
	return 0;
}