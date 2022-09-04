#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==1){
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		queue<int> bi,sma;
		while(!bi.empty())bi.pop();
		while(!sma.empty())sma.pop();
		for(int i=1;i<n;i+=2){
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			char c;
			cin>>c;
			if(c=='>')
			bi.push(i),sma.push(i+1);
			else
			bi.push(i+1),sma.push(i);
		}
		if(n%2!=0){
			printf("? %d %d\n",n,sma.front());
			fflush(stdout);
			char c;
			cin>>c;
			if(c=='<')
			sma.push(n),sma.pop();
			else
			bi.push(n);
		}
		int Max=bi.front();bi.pop();
		while(!bi.empty()){
			printf("? %d %d\n",Max,bi.front());
			fflush(stdout);
			char c;
			cin>>c;
			if(c=='<')
			Max=bi.front();
			bi.pop();
		}
		int Min=sma.front();sma.pop();
		while(!sma.empty()){
			printf("? %d %d\n",sma.front(),Min);
			fflush(stdout);
			char c;
			cin>>c;
			if(c=='<')
			Min=sma.front();
			sma.pop();
		}
		printf("! %d %d\n",Min,Max);
		fflush(stdout);
	}
}