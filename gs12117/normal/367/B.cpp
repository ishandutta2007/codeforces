#include<stdio.h>
#include<queue>
#include<algorithm>
int n,m,p;
int a[200100];
int b[200100];
int ans;
int ansl[200100];
std::priority_queue<int> pqa,pqb;
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<p;i++){
		if(i+(long long int)(m-1)*p>=n)break;
		for(j=0;j<m;j++){
			pqa.push(a[i+j*p]);
			pqb.push(b[j]);
		}
		for(j=0;i+(m+j)*p<n;j++){
			while(pqa.size()!=0&&pqa.top()==pqb.top()){
				pqa.pop();
				pqb.pop();
			}
			if(pqa.size()==0){
				ansl[ans]=i+j*p+1;
				ans++;
			}
			pqa.push(a[i+(m+j)*p]);
			pqb.push(a[i+j*p]);
		}
		while(pqa.size()!=0&&pqa.top()==pqb.top()){
			pqa.pop();
			pqb.pop();
		}
		if(pqa.size()==0){
			ansl[ans]=i+j*p+1;
			ans++;
		}
		while(pqa.size()!=0)pqa.pop();
		while(pqb.size()!=0)pqb.pop();
	}
	printf("%d\n",ans);
	std::sort(ansl,ansl+ans);
	for(i=0;i<ans;i++){
		printf("%d ",ansl[i]);
	}
}