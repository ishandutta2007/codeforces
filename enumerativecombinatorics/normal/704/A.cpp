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
int p[310000];
int at[310000];
vector<int>v[310000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int cnt=0;
	int ind=0;
	int num=0;
	for(int i=0;i<b;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==1){
			cnt++;
			v[y].push_back(num++);
		}else if(x==2){
			while(at[y]<v[y].size()){
				if(!p[v[y][at[y]]])cnt--;
				p[v[y][at[y]]]=1;
				at[y]++;
			}
		}else{
			while(ind<y){
				if(!p[ind])cnt--;
				p[ind]=1;
				ind++;
			}
		}
		printf("%d\n",cnt);
	}
}