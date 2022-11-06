#include<cstdio>
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)printf("%d %d\n",!(i%3)*3,i/3*2+(i%3>1));
}