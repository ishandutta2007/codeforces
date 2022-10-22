#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N];

int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int Min=-1,Max=-1;
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1])
				{Min=i;break;}
		}
		for(int i=n-1;i>=1;i--){
			if(a[i]==a[i+1])
				{Max=i;break;}
		}
		if(Min==-1||Min==Max) printf("0\n");
		else{
			printf("%d\n",mymax(1,Max-Min-1));
		}
	}
	
	return 0;
}