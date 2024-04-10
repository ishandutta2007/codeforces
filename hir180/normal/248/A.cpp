#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int ans1=0,ans2=0,ans3=0,ans4=0,n;
int a[12000][2];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
			if(a[i][0]==1){
				ans1++;
			}else if(a[i][0]==0){
				ans2++;
			}
			if(a[i][1]==0){
				ans3++;
			}else if(a[i][1]==1){
				ans4++;
			}
	}
	printf("%d\n",min(ans1,ans2)+min(ans3,ans4));
	return 0;
}