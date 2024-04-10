#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int a[110000];
map<int,int> B;

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		bool pd1=false,pd2=false,pd3=false,pd4=true;
		B.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0) pd1=true;
			if(a[i]==1) pd2=true;
			if(a[i]==2) pd3=true;
			if(B[a[i]-1]>0||B[a[i]+1]>0) pd4=false;
			B[a[i]]=1;
		}
		if(!pd2) printf("YES\n");
		else{
			if(pd4) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}