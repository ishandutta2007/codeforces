#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+100;
int a[N],left[N],right[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) left[i]=left[i-1]+1;
		else left[i]=0;
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]) right[i]=right[i+1]+1;
		else right[i]=0;
	}
	int Max=0;
	for(int i=1;i<=n;i++){
		if(Max<left[i]) Max=left[i];
		if(Max<right[i]) Max=right[i];
	}
	int Sum=0;
	for(int i=1;i<=n;i++){
		if(right[i]==Max||left[i]==Max) Sum++;
	}
	if(Sum>=2){
		printf("0\n");
		return 0;
	}
	int t;
	for(int i=1;i<=n;i++)
		if(right[i]==Max||left[i]==Max) {t=i;break;}
	if(right[t]==Max&&left[t]==Max){
		if(Max%2==0) printf("1\n");
		else printf("0\n");
	}
	else{
		printf("0\n");
		return 0;
	}
	return 0;
}