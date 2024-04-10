#include<bits/stdc++.h>
using namespace std;
map<int,int> chafen;
int main(){
	int n,firs;
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(i==1) firs=a;
		if(i!=1){
			chafen[a-b]++;
		}
		swap(a,b);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(i==1){
			if(firs!=a){
				printf("No\n");
			return 0;
			}
		}
		if(i!=1)
		{
		chafen[a-b]--;
		if(chafen[a-b]<0){
			printf("No\n");
			return 0;
		}
		}
		swap(a,b);
	}
	printf("Yes\n");
	return 0;
}