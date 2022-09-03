#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int main(){
	int n;
	scanf("%d",&n);
	map<char,int> m[3];
	char c[100005];
	int tot[3];//1,tot2,tot3;
	for(int i = 0;i<3;i++){
		scanf("%s",c);
		for(int j=0;c[j]!=0;j++)
			m[i][c[j]]++;
		tot[i]=strlen(c);
	}
	int ans[3]={1,1,1};
	for(int i=0;i<3;i++){
		for(auto it:m[i]){
			//now[i]=max(now[i],it.y);
			int num=it.y;
			num+=n;
			if(num>tot[i]){
				num=tot[i];
			}
			if(it.y==tot[i]&&n==1){
				num=tot[i]-1;
			}
			ans[i]=max(ans[i],num);
		}
	//	printf("%d",ans[i]);
	}
	if(ans[0]>ans[1]&&ans[0]>ans[2]){
		printf("Kuro\n");
	}
	else if(ans[1]>ans[0]&&ans[1]>ans[2]){
		printf("Shiro\n");
	}
	else if(ans[2]>ans[0]&&ans[2]>ans[1]){
		printf("Katie\n");
	}
	else{
		printf("Draw\n");
	}

}