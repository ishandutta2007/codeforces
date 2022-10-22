#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num;
	int now;
}p[200001];
int q,sum=0,num[200001];
bool cmp(node a,node b){
	return a.num<b.num;
}
int main(){
	scanf("%d",&n);
	p[1].num=1;
	p[1].now=1;
	for(int i=1;i<n;i++) {
		scanf("%d",&q);
		sum+=q;
		p[i+1].num=p[1].num+sum;
		p[i+1].now=i+1;
	}
	sort(p+1,p+1+n,cmp);
	bool OK=1;
	for(int i=1;i<n;i++){
//		cout<<p[i].num<<endl; 
		if(!(p[i].num==p[i+1].num-1)) OK=0; 
	}
	if(!OK)	printf("-1\n");
	else{
		for(int i=1;i<=n;i++){
		num[p[i].now]=i;
//		cout<<p[i].now<<" "<<i<<endl;
		}
		for(int i=1;i<=n;i++){
		printf("%d ",num[i]);
		}
	}
	return 0;
}