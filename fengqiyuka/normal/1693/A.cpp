#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N];

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		ll Sum=0;
		for(int i=1;i<=n;i++) Sum+=a[i];
		if(Sum!=0){
			printf("No\n");
			continue;
		}
		Sum=0;bool pd=true;
		for(int i=1;i<=n;i++){
			Sum+=a[i];
			if(Sum<0) {pd=false;break;}
		}
		if(!pd){
			printf("No\n");
			continue;
		}
		int id=0;
		for(int i=1;i<=n;i++){
			Sum+=a[i];id++;
			if(Sum==0) break;
		}
		for(int i=id+1;i<=n;i++)
			if(a[i]!=0) {pd=false;break;}
		if(!pd){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	
	return 0;
}