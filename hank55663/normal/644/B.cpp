#include<bits/stdc++.h>
using namespace std;
struct aa{
	int a,b;
};
main(){
	int Q,d;
	scanf("%d %d",&Q,&d);
	queue<aa> q;
	long long int time=0,nowtime=0;
	int a,b;
	scanf("%d %d",&a,&b);
	time=a+b;
	nowtime=a+b;
	printf("%lld",time);
	Q--;
	while(Q--){
		aa a;
		scanf("%d %d",&a.a,&a.b);
		while(a.a>=nowtime&&!q.empty()){
			nowtime+=q.front().b;
			q.pop();
		}
		if(a.a<time){
			if(q.size()<d){
				q.push(a);
				printf(" %I64d",time+=a.b);
			}
			else{
				printf(" -1");
				continue;
			}
		}
		else{
			time= a.a+a.b;	
			nowtime=a.a+a.b	;printf(" %I64d",time);	
		}
		
	}
	printf("\n");
}